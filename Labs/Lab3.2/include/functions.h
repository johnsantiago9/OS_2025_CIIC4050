#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <ncurses.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ROWS 15
#define COLUMNS 25
#define ENTER_NCURSES 10

// Structure to store ball position
typedef struct {
  int x;
  int y;
} BallState;

// Declare global variables
extern BallState ball;
extern int remaining_obstacles;
extern int terminate_flag;
extern int move_x, move_y;
extern int grid[ROWS][COLUMNS];
extern pthread_mutex_t game_lock;
extern int term_rows, term_cols;
extern int difficulty_level;
extern int move_counter;
extern int control_mode;  // 0 = automatic, 1 = manual

/**
 * @brief Updates the position and state of the ball.
 *
 * This function is intended to be used as a thread function.
 * It continuously updates the ball's movement based on game logic.
 *
 * @param param Pointer to any parameters needed for the function (can be NULL).
 * @return A pointer to the result (can be NULL if not needed).
 */
void *UpdateBall(void *param);

/**
 * @brief Renders the game screen.
 *
 * This function is responsible for rendering the game objects onto the screen.
 * It is typically called within the game loop to refresh the display.
 *
 * @param param Pointer to any parameters needed for the function (can be NULL).
 * @return A pointer to the result (can be NULL if not needed).
 */
void *RenderScreen(void *param);

/**
 * @brief Handles keyboard input from the user.
 *
 * This function captures keyboard events and updates game states
 * accordingly based on user input.
 *
 * @param param Pointer to any parameters needed for the function (can be NULL).
 * @return A pointer to the result (can be NULL if not needed).
 */
void *KeyboardInput(void *param);

/**
 * @brief Sets up the game grid.
 *
 * Initializes the game grid, including allocating memory and
 * setting up the initial game state.
 */
void SetupGrid();

#endif
