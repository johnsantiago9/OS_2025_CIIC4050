#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <ncurses.h>
#include <stdio.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/time.h>
#include <errno.h>

#define MAX_LINE_LENGTH 256

// Data structure to keep shared info
typedef struct {
    FILE *fp;
    WINDOW *win;
    int done;
    int x, y;              
    int has_new_coord;
    struct timespec last_time;
    FILE *log_fp;
} SharedData;

extern SharedData *g_data;
extern volatile sig_atomic_t g_flag;

/**
 * @brief Initialize ncurses
 * 
 * @param win Pointer to ncurses window
 * @return int 0 if success, -1 if failed
 */
int InitNcurses(WINDOW **win);
/**
 * @brief Close ncurses
 * 
 * @return void
 */
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
void TimerHandler(int sig);

/**
 * @brief Read next coordinate from file
 * 
 * @param data Shared data structure
 * @return int 0 if success, -1 if failed
 */
int ReadNextCoordinate(SharedData *data);

/**
 * @brief Update screen position of the asterisk
 * 
 * @param data Shared data structure
 * @return void
 */
void UpdateScreenPosition(SharedData *data);

/**
 * @brief Log the time interval between updates
 * 
 * @param data Shared data structure
 * @return void
 */
void LogTimeInterval(SharedData *data);

#endif
