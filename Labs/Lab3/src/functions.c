#include "functions.h"


// Function to initialize screen
void init_screen() {
  initscr();
  keypad(stdscr, TRUE);
  noecho();
  curs_set(0);
}
// Function to close screen
void close_screen() {
  endwin();
}

void *keyboard_input(void *arg) {
  Ball *ball = (Ball *)arg;
  int ch;

  while (1) {
    // Get user input
    ch = getch();
    pthread_mutex_lock(&ball->lock);
    // Handle user input
    switch (ch) {
      case ' ':
        ball->manual_mode = !ball->manual_mode;
        break;
      case KEY_UP:
        if (ball->manual_mode && ball->y > 1) {
          ball->y--;
          ball->movement_count++; // Increment counter
        }
        break;
      case KEY_DOWN:
        if (ball->manual_mode && ball->y < ball->max_y - 2) {
          ball->y++;
          ball->movement_count++;
        }
        break;
      case KEY_LEFT:
        if (ball->manual_mode && ball->x > 1) {
          ball->x--;
          ball->movement_count++;
        }
        break;
      case KEY_RIGHT:
        if (ball->manual_mode && ball->x < ball->max_x - 2) {
          ball->x++;
          ball->movement_count++;
        }
        break;
    }
    pthread_mutex_unlock(&ball->lock);
  }
  return NULL;
}
// Function to update ball position
void *update_ball_position(void *arg) {
  Ball *ball = (Ball *)arg;

  while (1) {
    // Update ball position
    pthread_mutex_lock(&ball->lock);
    if (!ball->manual_mode) {
      ball->x += ball->dx;
      ball->y += ball->dy;
      ball->movement_count++; // Increment counter

      if (ball->x >= ball->max_x - 1 || ball->x <= 1) {
        ball->dx *= -1;
      }
      if (ball->y >= ball->max_y - 1 || ball->y <= 1) {
        ball->dy *= -1;
      }
    }
    pthread_mutex_unlock(&ball->lock);
    usleep(100000);
  }
  return NULL;
}

void *draw_screen(void *arg) {
  Ball *ball = (Ball *)arg;
  int max_y, max_x;

  while (1) {
    pthread_mutex_lock(&ball->lock);
    
    // Update max_x and max_y dynamically
    getmaxyx(stdscr, max_y, max_x);
    ball->max_x = max_x;
    ball->max_y = max_y;

    clear();
    mvprintw(0, 0, "Mode: %s", ball->manual_mode ? "MANUAL" : "AUTOMATIC");
    mvprintw(1, 0, "Movements: %d", ball->movement_count);  // Display counter

    // Ensure the ball stays within new boundaries
    if (ball->x >= ball->max_x) ball->x = ball->max_x - 2;
    if (ball->y >= ball->max_y) ball->y = ball->max_y - 2;

    mvprintw(ball->y, ball->x, "o");
    refresh();
    pthread_mutex_unlock(&ball->lock);
    usleep(50000);
  }
  return NULL;
}
