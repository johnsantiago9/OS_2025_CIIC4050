#include "functions.h"
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

/**
 * @brief Checks if a file contains a specific word.
 *
 * This function reads the contents of a file and checks if it contains a
 * specific word.
 *
 * @param filepath The path to the file to be checked.
 * @param word The word to be searched for.
 * @return 1 if the word is found, 0 otherwise.
 */
int ContainsWord(const char *filepath, const char *word) {
  int fd = open(filepath, O_RDONLY);
  if (fd < 0) {
    perror("Error opening file");
    return 0;
  }

  char buffer[BUFFER_SIZE];
  ssize_t bytes_read;
  while ((bytes_read = read(fd, buffer, sizeof(buffer) - 1)) > 0) {
    buffer[bytes_read] = '\0';
    if (strstr(buffer, word) != NULL) {
      close(fd);
      return 1;
    }
  }

  close(fd);
  return 0;
}

/**
 * @brief Explores a directory and its subdirectories to find files containing a
 * specific word.
 *
 * This function explores a directory and its subdirectories recursively to find
 * files that contain a specific word. If a file contains the word, its path is
 * printed to the standard output.
 *
 * @param dirpath The path to the directory to be explored.
 * @param word The word to be searched for.
 */
void ExploreDirectory(const char *dirpath, const char *word) {
  DIR *dir = opendir(dirpath);
  char cwd[1024];
  if (getcwd(cwd, sizeof(cwd)) != NULL) {
    printf("Current working dir: %s\n", cwd);
  }

    if (!dir) {
      perror("Error opening directory");
      return;
    }

    struct dirent *entry;
    char filepath[1024];

    while ((entry = readdir(dir)) != NULL) {
      // Ignore "." and ".." entries
      if (entry->d_name[0] == '.') continue;

      snprintf(filepath, sizeof(filepath), "%s/%s", dirpath, entry->d_name);

      struct stat path_stat;
      stat(filepath, &path_stat);

      if (S_ISREG(path_stat.st_mode)) {
        if (ContainsWord(filepath, word)) {
          printf("Found in: %s\n", filepath);
        }
      }
    }

    closedir(dir);
  }