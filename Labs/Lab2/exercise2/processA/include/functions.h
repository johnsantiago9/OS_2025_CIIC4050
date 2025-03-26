#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <fcntl.h>
#include <semaphore.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>

#define SHM_NAME "/shm_example"
#define SHM_SIZE 4096
#define SEM_NAME "/mysem"
#define MAX_NUMBERS 1000

extern float *shm_ptr;
extern sem_t *sem;

void SetupSharedMemory();
void SetupSemaphore();
void InitializeMemory();
void SignalHandlerSetup();
void HandleSigusr1(int sig);
void HandleSigusr2(int sig);
void HandleSigalrm(int sig);
void UserMenu(float *shm_ptr, pid_t process_b_pid);
void PrintSharedMemory();
void Cleanup(float *shm_ptr, sem_t *sem);

#endif