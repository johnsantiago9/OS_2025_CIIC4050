#include "functions.h"

float *shm_ptr;
sem_t *sem;

/**
 * @brief Sets up shared memory by opening and mapping it.
 *
 * This function opens a shared memory segment with a predefined name and maps
 * it into the process's address space. It initializes all elements in the
 * shared memory to zero.
 */
void SetupSharedMemory() {
    shm_unlink(SHM_NAME);
  int fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);  // Opens shared memory
  if (fd == -1) {
    perror("shm_open failed");
    exit(1);
  }

  if (ftruncate(fd, SHM_SIZE) == -1) {
    perror("ftruncate failed");
    exit(1);
  }

  shm_ptr = mmap(0, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd,
                 0);  // Maps the memory
  if (shm_ptr == MAP_FAILED) {
    perror("mmap failed");
    exit(1);
  }

  // Initialize all values inside shared memory to 0
  for (int i = 0; i < MAX_NUMBERS; i++) {
    shm_ptr[i] = 0.0;
  }
}

/**
 * @brief Sets up a named semaphore for process synchronization.
 *
 * This function creates or opens a named semaphore with an initial value of 1,
 * ensuring mutual exclusion when accessing shared memory.
 */
void SetupSemaphore() {
  sem = sem_open(SEM_NAME, O_CREAT, 0666, 1);  // Opens the semaphore
  if (sem == SEM_FAILED) {
    perror("sem_open failed");
    exit(1);
  }
}

/**
 * @brief Prints the current values in the shared memory.
 */
void PrintSharedMemory() {
  sem_wait(sem);  // Lock the semaphore
  for (int i = 0; i < MAX_NUMBERS; i++) {
    if (shm_ptr[i] != 0.0) {
      printf("%f ", shm_ptr[i]);
    }
  }
  printf("\n");
  sem_post(sem);  // Unlock the semaphore
}

/**
 * @brief Cleans up shared memory and semaphore.
 *
 * This function unmaps the shared memory, closes the semaphore, and unlinks the
 * shared memory and semaphore.
 */
void Cleanup(float *shm_ptr, sem_t *sem) {
  munmap(shm_ptr, SHM_SIZE);
  sem_close(sem);
  sem_unlink(SEM_NAME);
  shm_unlink(SHM_NAME);
}

/**
 * @brief Displays the user menu and handles user input.
 *
 * This function displays a menu to the user and handles the user's choice by
 * sending the appropriate signal to Process B.
 */
void UserMenu(float *shm_ptr, pid_t process_b_pid) {
  int choice;
  while (1) {
    printf("\nMenu:\n");
    printf("1. Include new number [SIGUSR1]\n");
    printf("2. Delete the last number [SIGUSR2]\n");
    printf("3. Divide number values by two [SIGALRM]\n");
    printf("4. Print current numbers\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        kill(process_b_pid, SIGUSR1);  // Send SIGUSR1 to Process B
        break;
      case 2:
        kill(process_b_pid, SIGUSR2);  // Send SIGUSR2 to Process B
        break;
      case 3:
        kill(process_b_pid, SIGALRM);  // Send SIGALRM to Process B
        break;
      case 4:
        PrintSharedMemory();
        break;
      case 5:
        Cleanup(shm_ptr, sem);
        kill(process_b_pid, SIGKILL);  // Terminate Process B
        exit(0);
      default:
        printf("Invalid choice. Please try again.\n");
    }
  }
}