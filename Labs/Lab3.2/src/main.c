#include "functions.h"

// Define global variables
BallState ball = {COLUMNS / 2, ROWS / 2};
int remaining_obstacles = 0;
int terminate_flag = 0;
int move_x = 1, move_y = 1;
int grid[ROWS][COLUMNS];
pthread_mutex_t game_lock;
int term_rows, term_cols;
int difficulty_level;
int move_counter = 0;
int control_mode = 0; // 0 = auto, 1 = manual

int main() {
    initscr();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);

    pthread_mutex_init(&game_lock, NULL);

    //Difficulty selection BEFORE threads start
    mvprintw(0, 0, "Select difficulty: 1 (Low), 2 (Medium), 3 (High)");
    refresh();
    
    while (1) {
        int ch = getch();
        if (ch == '1') { difficulty_level = 1; remaining_obstacles = ((ROWS - 2) * (COLUMNS - 2)) * 0.25; break; }
        if (ch == '2') { difficulty_level = 2; remaining_obstacles = ((ROWS - 2) * (COLUMNS - 2)) * 0.50; break; }
        if (ch == '3') { difficulty_level = 3; remaining_obstacles = ((ROWS - 2) * (COLUMNS - 2)) * 0.75; break; }
    }

    // Clear the screen after difficulty is selected
    clear();
    refresh();

    //Initialize the grid AFTER difficulty is chosen
    SetupGrid();

    // Create threads
    pthread_t input_thread, ball_thread, screen_thread;
    pthread_create(&input_thread, NULL, KeyboardInput, NULL);
    pthread_create(&ball_thread, NULL, UpdateBall, NULL);
    pthread_create(&screen_thread, NULL, RenderScreen, NULL);

    // Wait for threads to finish (Game Over should be displayed)
    pthread_join(screen_thread, NULL);

    // Cleanup
    pthread_mutex_destroy(&game_lock);
    endwin();
    return 0;
}
