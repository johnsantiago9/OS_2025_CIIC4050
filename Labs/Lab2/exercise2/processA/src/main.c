#include "functions.h"

int main() {
  pid_t process_b_pid = fork();  // Create Process B

  if (process_b_pid == 0) {
    // Child Process (Process B)
    execl("../../processB/build/processB", "./processB", NULL);
    perror("execl failed");
    exit(1);
  } else if (process_b_pid > 0) {
    // Parent Process (Process A)
    SetupSharedMemory();
    SetupSemaphore();
    UserMenu(shm_ptr, process_b_pid);  // Pass PID to user_menu
  } else {
    perror("fork failed");
    exit(1);
  }

  return 0;
}