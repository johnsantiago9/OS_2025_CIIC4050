#include "functions.h"

// Use extern variables defined in `main.c`
extern BallState ball;
extern int remaining_obstacles;
extern int terminate_flag;
extern int move_x, move_y;
extern int grid[ROWS][COLUMNS];
extern pthread_mutex_t game_lock;
extern int difficulty_level;
extern int control_mode; // 0 = automatic, 1 = manual

// Function to handle user input for switching modes and moving ball
void *KeyboardInput(void *param) {
    while (!terminate_flag) {
        int ch = getch();
        pthread_mutex_lock(&game_lock);

        if (ch == ' ') {
            control_mode = !control_mode; // Toggle between auto and manual mode
        }

        if (control_mode == 1) { // Manual mode
            int new_x = ball.x;
            int new_y = ball.y;

            switch (ch) {
                case KEY_UP:
                    if (ball.y > 1) new_y--;
                    break;
                case KEY_DOWN:
                    if (ball.y < ROWS - 2) new_y++;
                    break;
                case KEY_LEFT:
                    if (ball.x > 1) new_x--;
                    break;
                case KEY_RIGHT:
                    if (ball.x < COLUMNS - 2) new_x++;
                    break;
            }

            // If moving onto an obstacle, remove it
            if (grid[new_y][new_x] == 2) {
                grid[new_y][new_x] = 0;
                remaining_obstacles--;
            }

            // Update ball position
           if (new_x != ball.x || new_y != ball.y) {
                ball.x = new_x;
                ball.y = new_y;
                move_counter++; 
        }
    }

        pthread_mutex_unlock(&game_lock);
    }
    pthread_exit(NULL);
}



// Function to update ball movement and handle collision
void *UpdateBall(void *param) {
    while (!terminate_flag) {
        pthread_mutex_lock(&game_lock);

        if (control_mode == 0) { // Auto mode
            ball.x += move_x;
            ball.y += move_y;
            move_counter++;

            //left and right boundary issues
            if (ball.x <= 1) {
                ball.x = 1;
                move_x = 1; // Change direction
            }
            if (ball.x >= COLUMNS - 2) {
                ball.x = COLUMNS - 2;
                move_x = -1;
            }

            //top and bottom boundary issues
            if (ball.y <= 1) {
                ball.y = 1;
                move_y = 1;
            }
            if (ball.y >= ROWS - 2) {
                ball.y = ROWS - 2;
                move_y = -1;
            }

            // Handle obstacle collisions
            if (grid[ball.y][ball.x] == 2) {
                grid[ball.y][ball.x] = 0; // Remove obstacle
                remaining_obstacles--;
                move_x = -move_x;
                move_y = -move_y;
            }
        }

        pthread_mutex_unlock(&game_lock);
        usleep(100000);
    }
    pthread_exit(NULL);
}


// Function to render game state
void *RenderScreen(void *param) {
    while (!terminate_flag) {
        pthread_mutex_lock(&game_lock);
        getmaxyx(stdscr, term_rows, term_cols);

        clear();
        mvprintw(0, 0, "Mode: %s", (control_mode == 0) ? "Auto" : "Manual");
        mvprintw(1, 0, "Remaining obstacles: %d", remaining_obstacles);
        mvprintw(0, 15, "Moves: %d", move_counter);

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLUMNS; j++) {
                if (grid[i][j] == 1) mvprintw(i + 2, j, "*");  // Border
                else if (grid[i][j] == 2) mvprintw(i + 2, j, "#"); // Obstacle
                else mvprintw(i + 2, j, " "); // Clear empty spaces
            }
        }

        mvprintw(ball.y + 2, ball.x, "o"); // Draw the ball

        //"Game Over" message appears when all obstacles are cleared
        if (remaining_obstacles == 0) {
            clear();
            mvprintw(term_rows / 2, (term_cols / 2) - 5, "GAME OVER!");
            mvprintw((term_rows / 2) + 1, (term_cols / 2) - 9, "Press any key to exit");
            refresh();
            pthread_mutex_unlock(&game_lock);

            // Prevent game from closing immediately
            usleep(2000000); //Allow message to stay on screen for 2 seconds
            getch(); // Wait for user input before closing

            terminate_flag = 1; // safely terminate the game
            pthread_exit(NULL);
        }

        pthread_mutex_unlock(&game_lock);
        refresh();
        usleep(100000);
    }
    pthread_exit(NULL);
}



// Function to initialize the game grid
void SetupGrid() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            grid[i][j] = (i == 0 || i == ROWS - 1 || j == 0 || j == COLUMNS - 1) ? 1 : 0;
        }
    }

    int placed = 0;
    while (placed < remaining_obstacles) {
        int x = rand() % (COLUMNS - 2) + 1;
        int y = rand() % (ROWS - 2) + 1;
        if (grid[y][x] == 0) {
            grid[y][x] = 2;
            placed++;
        }
    }
}
