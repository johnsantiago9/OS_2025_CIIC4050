#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <ncurses.h>
#include <pthread.h>
#include <unistd.h>

typedef struct {
  int x;
  int y;
  int dx;
  int dy;
  int max_x;
  int max_y;
  int manual_mode;
  int movement_count;
  pthread_mutex_t lock;
} Ball;

/**
 * @brief Initializes the game screen.
 *
 * This function sets up the screen, including any necessary
 * configurations for rendering and input handling.
 */
void init_screen();

/**
 * @brief Closes the game screen.
 *
 * This function cleans up resources related to the screen before exiting the
 * program. It ensures proper deallocation of memory and shuts down any
 * rendering systems.
 */
void close_screen();

/**
 * @brief Handles keyboard input from the user.
 *
 * This function continuously listens for keyboard events and updates
 * the game state accordingly. It is designed to run as a separate thread.
 *
 * @param arg Pointer to any parameters needed for the function (can be NULL).
 * @return A pointer to the result (can be NULL if not needed).
 */
void *keyboard_input(void *arg);

/**
 * @brief Updates the position of the ball.
 *
 * This function is responsible for updating the ball's movement based on game
 * logic. It runs as a separate thread to update the ball's position
 * asynchronously.
 *
 * @param arg Pointer to any parameters needed for the function (can be NULL).
 * @return A pointer to the result (can be NULL if not needed).
 */
void *update_ball_position(void *arg);

/**
 * @brief Renders the game screen.
 *
 * This function is responsible for drawing all game objects onto the screen.
 * It runs as a separate thread and refreshes the display at a regular interval.
 *
 * @param arg Pointer to any parameters needed for the function (can be NULL).
 * @return A pointer to the result (can be NULL if not needed).
 */
void *draw_screen(void *arg);

#endif
