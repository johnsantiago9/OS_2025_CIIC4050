#include "functions.h"


int InitNcurses(WINDOW **win) {
    initscr();           
    cbreak();             
    noecho();             
    keypad(stdscr, TRUE); 
    curs_set(0);          

    *win = newwin(24, 80, 0, 0);
    if (!(*win)) {
        return -1;
    }

    nodelay(*win, TRUE);
    return 0;
}

void CloseNcurses() {
    endwin();
}

void InitSharedData(SharedData *data, const char *filename, const char *log_filename) {
    data->fp = fopen(filename, "r");
    if (!data->fp) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(1);
    }

    data->log_fp = fopen(log_filename, "w");
    if (!data->log_fp) {
        fprintf(stderr, "Error opening log file: %s\n", log_filename);
        fclose(data->fp);
        exit(1);
    }

    data->x = 0;
    data->y = 0;
    data->done = 0;
    pthread_mutex_init(&data->lock, NULL);

    clock_gettime(CLOCK_MONOTONIC, &data->last_time);
}

void DestroySharedData(SharedData *data) {
    if (data->fp) {
        fclose(data->fp);
    }
    if (data->log_fp) {
        fclose(data->log_fp);
    }
    pthread_mutex_destroy(&data->lock);
}

// Thread function: runs a loop with usleep(50000)
void *UpdateThread(void *arg) {
    SharedData *data = (SharedData *)arg;
    char line[MAX_LINE_LENGTH];

    while (1) {
        // Sleep ~50ms
        usleep(50000);

        // Measure time interval
        struct timespec now;
        clock_gettime(CLOCK_MONOTONIC, &now);
        LogTimeInterval(data, &now);

        // Read next coordinate
        pthread_mutex_lock(&data->lock);
        if (!fgets(line, sizeof(line), data->fp)) {
            // End of file or error
            data->done = 1;
            pthread_mutex_unlock(&data->lock);
            break;
        }
        // parse x,y
        int x_coor, y_coor;
        if (sscanf(line, "%d,%d", &x_coor, &y_coor) == 2) {
            data->x = x_coor;
            data->y = y_coor;
            UpdateScreenPosition(data);
        }
        pthread_mutex_unlock(&data->lock);
    }

    return NULL;
}

// Update screen position
void UpdateScreenPosition(SharedData *data) {
    werase(data->win);
    mvwprintw(data->win, data->y, data->x, "*");
    wrefresh(data->win);
}

// Log the time interval

void LogTimeInterval(SharedData *data, struct timespec *current_time) {
    double elapsed_ms = (current_time->tv_sec - data->last_time.tv_sec) * 1000.0 +
                        (current_time->tv_nsec - data->last_time.tv_nsec) / 1e6;

    fprintf(data->log_fp, "%.3f\n", elapsed_ms);
    fflush(data->log_fp);

    data->last_time = *current_time;
}
