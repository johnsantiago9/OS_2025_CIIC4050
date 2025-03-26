#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <ncurses.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LINE_LENGTH 256

typedef struct {
    FILE *fp;
    FILE *log_fp;
    WINDOW *win;
    pthread_mutex_t lock;
    int x, y;
    int done;
    struct timespec last_time;
} SharedData;

// Functions
int InitNcurses(WINDOW **win);
void CloseNcurses();

/**
 * @brief Initialize shared data
 * 
 * @param data Shared data structure
 * @param filename Path to file with coordinates
 * @param log_filename Path to log file
 * @return void
 */
void InitSharedData(SharedData *data, const char *filename, const char *log_filename);

/**
 * @brief Destroy shared data
 * 
 * @param data Shared data structure
 * @return void
 */
void DestroySharedData(SharedData *data);

/**
 * @brief Thread function: runs a loop with usleep(50000)
 * 
 * @param arg Shared data structure
 * @return void*
 */
void *UpdateThread(void *arg);

/**
 * @brief Update screen position
 * 
 * @param data Shared data structure
 * @return void
 */
void UpdateScreenPosition(SharedData *data);

/**
 * @brief Log time interval
 * 
 * @param data Shared data structure
 * @param current_time Current time
 * @return void
 */
void LogTimeInterval(SharedData *data, struct timespec *current_time);

#endif
