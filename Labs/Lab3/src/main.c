#include "functions.h"

int main() {
  pthread_t keyboard_thread, ball_thread, draw_thread;

  Ball ball = {
    .x = 10,
    .y = 5,
    .dx = 1,
    .dy = 1,
    .manual_mode = 0,
    .lock = PTHREAD_MUTEX_INITIALIZER
  };

  init_screen();
  getmaxyx(stdscr, ball.max_y, ball.max_x);
  pthread_create(&keyboard_thread, NULL, keyboard_input, (void *)&ball);
  pthread_create(&ball_thread, NULL, update_ball_position, (void *)&ball);
  pthread_create(&draw_thread, NULL, draw_screen, (void *)&ball);

  pthread_join(keyboard_thread, NULL);
  pthread_join(ball_thread, NULL);
  pthread_join(draw_thread, NULL);

  close_screen();
  return 0;
}
