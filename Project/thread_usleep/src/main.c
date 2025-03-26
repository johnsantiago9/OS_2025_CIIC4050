#include "functions.h"


int main(void) {
    // Prompt user which file to load
    int choice = 0;
    while (choice != 1 && choice != 2) {
        printf("Choose path file:\n");
        printf("  1) path_1.txt\n");
        printf("  2) path_2.txt\n");
        printf("Enter choice (1 or 2): ");
        scanf("%d", &choice);

        if (choice != 1 && choice != 2) {
            printf("Invalid choice. Please try again.\n");
        }
    }
    // Select path file and log file
    const char *coords_file = (choice == 1) ? "../../path_1.txt" : "../../path_2.txt";
    const char *log_file = "thread_log.txt";

    // Initialize ncurses
    WINDOW *win;
    if (InitNcurses(&win) != 0) {
        fprintf(stderr, "Failed to initialize ncurses.\n");
        return 1;
    }

    // Prepare shared data
    SharedData data;
    data.win = win;
    InitSharedData(&data, coords_file, log_file);

    // Create worker thread
    pthread_t tid;
    if (pthread_create(&tid, NULL, UpdateThread, &data) != 0) {
        fprintf(stderr, "Error creating thread.\n");
        CloseNcurses();
        DestroySharedData(&data);
        return 1;
    }


    while (!data.done) {
        usleep(1000);
    }

    pthread_join(tid, NULL);

    // Cleanup
    CloseNcurses();
    DestroySharedData(&data);

    return 0;
}
