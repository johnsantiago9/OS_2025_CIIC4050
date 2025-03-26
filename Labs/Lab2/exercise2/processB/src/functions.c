#include "functions.h"

float *shm_ptr;
sem_t *sem;

/**
 * @brief Sets up shared memory by opening and mapping it.
 *
 * This function opens an existing shared memory segment created by Process A
 * and maps it into the process's address space.
 */
void SetupSharedMemory() {
  // Open the existing shared memory created by Process A
  int fd = shm_open(SHM_NAME, O_RDWR, 0666);
  if (fd == -1) {
    perror("shm_open failed");
    exit(1);
  }
  shm_ptr = mmap(0, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
  if (shm_ptr == MAP_FAILED) {
    perror("mmap failed");
    exit(1);
  }
}

/**
 * @brief Sets up a named semaphore for process synchronization.
 *
 * This function opens an existing named semaphore without creating it.
 */
void SetupSemaphore() {
  // Open the existing semaphore without creating it
  sem = sem_open(SEM_NAME, 0);
  if (sem == SEM_FAILED) {
    perror("sem_open failed");
    exit(1);
  }
}

/**
 * @brief Sets up signal handlers for SIGUSR1, SIGUSR2, and SIGALRM.
 *
 * This function installs the signal handlers for SIGUSR1, SIGUSR2, and SIGALRM.
 */
void SignalHandlerSetup() {
  signal(SIGUSR1, HandleSigusr1);
  signal(SIGUSR2, HandleSigusr2);
  signal(SIGALRM, HandleSigalrm);
}

/**
 * @brief Handles SIGUSR1 signal.
 *
 * This function adds a new number to the shared memory array.
 *
 * @param sig Signal number.
 */
void HandleSigusr1(int sig) {
  sem_wait(sem);
  for (int i = 0; i < MAX_NUMBERS; i++) {
    if (shm_ptr[i] == 0.0) {
      shm_ptr[i] = (i == 0) ? 1.0 : shm_ptr[i - 1] * 2;
      break;
    }
  }
  sem_post(sem);
}

/**
 * @brief Handles SIGUSR2 signal.
 *
 * This function deletes the last number from the shared memory array.
 *
 * @param sig Signal number.
 */
void HandleSigusr2(int sig) {
  sem_wait(sem);
  for (int i = MAX_NUMBERS - 1; i >= 0; i--) {
    if (shm_ptr[i] != 0.0) {
      shm_ptr[i] = 0.0;
      break;
    }
  }
  sem_post(sem);
}

/**
 * @brief Handles SIGALRM signal.
 *
 * This function divides all numbers in the shared memory array by two.
 *
 * @param sig Signal number.
 */
void HandleSigalrm(int sig) {
  sem_wait(sem);
  for (int i = 0; i < MAX_NUMBERS; i++) {
    if (shm_ptr[i] != 0.0) {
      shm_ptr[i] /= 2;
    }
  }
  sem_post(sem);
}