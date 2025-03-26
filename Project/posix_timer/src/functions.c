#include "functions.h"

// Global shared data pointer (used by signal handler)
SharedData *g_data = NULL;
volatile sig_atomic_t g_flag = 0;

// ncurses initialization
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

// Shared data initialization
void InitSharedData(SharedData *data, const char *filename, const char *log_filename) {
    data->fp = fopen(filename, "r");
    if (!data->fp) {
        fprintf(stderr, "Error opening file %s\n", filename);
        exit(1);
    }

    data->log_fp = fopen(log_filename, "w");
    if (!data->log_fp) {
        fprintf(stderr, "Error opening log file %s\n", log_filename);
        fclose(data->fp);
        exit(1);
    }

    data->done = 0;
    data->x = 0;
    data->y = 0;
    data->has_new_coord = 0;

    clock_gettime(CLOCK_MONOTONIC, &data->last_time);
}

void DestroySharedData(SharedData *data) {
    if (data->fp) {
        fclose(data->fp);
    }
    if (data->log_fp) {
        fclose(data->log_fp);
    }
}

// Timer handler
void TimerHandler(int sig) {
    // Set a flag that indicates we should do an update
    g_flag = 1;
}

// Read next coordinate
int ReadNextCoordinate(SharedData *data) {
    char line[MAX_LINE_LENGTH];
    if (!fgets(line, sizeof(line), data->fp)) {
        // End of file or error
        return 0;
    }

    // Parse x,y from line
    int x_coor, y_coor;
    if (sscanf(line, "%d,%d", &x_coor, &y_coor) != 2) {
        fprintf(stderr, "Malformed line: %s\n", line);
        return 0;
    }

    data->x = x_coor;
    data->y = y_coor;
    data->has_new_coord = 1;
    return 1;
}

// Update screen position
void UpdateScreenPosition(SharedData *data) {
    werase(data->win);
    // Print the asterisk at (y, x). In ncurses, y is row, x is column.
    mvwprintw(data->win, data->y, data->x, "*");
    wrefresh(data->win);
}


// Log the time interval
void LogTimeInterval(SharedData *data) {
    struct timespec now;
    clock_gettime(CLOCK_MONOTONIC, &now);

    double elapsed_ms = (now.tv_sec - data->last_time.tv_sec) * 1000.0 +
                        (now.tv_nsec - data->last_time.tv_nsec) / 1e6;

    fprintf(data->log_fp, "%.3f\n", elapsed_ms);
    fflush(data->log_fp);

    data->last_time = now;
}
