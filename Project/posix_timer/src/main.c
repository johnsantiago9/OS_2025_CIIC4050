#include "functions.h"



int main(void) {
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
    const char *log_file = "timer_log.txt";

    // Initialize ncurses
    WINDOW *win;
    if (InitNcurses(&win) != 0) {
        fprintf(stderr, "Failed to initialize ncurses.\n");
        return 1;
    }

    // Create and init shared data
    SharedData data;
    data.win = win;
    InitSharedData(&data, coords_file, log_file);
    g_data = &data;

    // Setup the signal handler
    struct sigaction sa;
    sa.sa_handler = TimerHandler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    if (sigaction(SIGALRM, &sa, NULL) == -1) {
        perror("sigaction");
        CloseNcurses();
        DestroySharedData(&data);
        return 1;
    }

    // Create a POSIX timer
    timer_t timerid;
    struct sigevent sev;
    struct itimerspec its;
    memset(&sev, 0, sizeof(sev));
    sev.sigev_notify = SIGEV_SIGNAL;
    sev.sigev_signo = SIGALRM;

    if (timer_create(CLOCK_REALTIME, &sev, &timerid) == -1) {
        perror("timer_create");
        CloseNcurses();
        DestroySharedData(&data);
        return 1;
    }

    // Interval: 50ms
    its.it_value.tv_sec = 0;
    its.it_value.tv_nsec = 50 * 1000000;      // 50ms
    its.it_interval.tv_sec = 0;
    its.it_interval.tv_nsec = 50 * 1000000;   // 50ms repeating

    if (timer_settime(timerid, 0, &its, NULL) == -1) {
        perror("timer_settime");
        CloseNcurses();
        DestroySharedData(&data);
        return 1;
    }

    // Main loop: wait for the timer flag
    while (!data.done) {
        if (g_flag) {
            g_flag = 0;

            // Read next coordinate
            if (!ReadNextCoordinate(&data)) {
                // We reached EOF or error
                data.done = 1;
                continue;
            }

            // Log the actual timing interval
            LogTimeInterval(&data);

            // Update screen
            if (data.has_new_coord) {
                UpdateScreenPosition(&data);
            }
        }
        // Prevent busy looping
        usleep(1000);
    }

    // Cleanup
    timer_delete(timerid);
    CloseNcurses();
    DestroySharedData(&data);

    return 0;
}
