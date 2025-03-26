#include "functions.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>


// Then, create another program that asks the user for a folder path and a word
// of their choice. This program must create a child process that executes the
// word_explorer program using the exec system call to list all the files
// containing the word the user selects.
int main(){
    char folder_path[100], word[100];
    printf("Enter the folder path: ");
    scanf("%s", folder_path);
    printf("Enter the word: ");
    scanf("%s", word);
    
    pid_t pid = fork();
    if (pid < 0) {
        perror("Error forking");
        return 1;
    }
    if (pid == 0) {
        // Child process
        execlp("../word_explorer/word_explorer/build/word_explorer", "word_explorer", folder_path, word, NULL);
        perror("Error executing word_explorer");
        return 1;
    }
    //char *args[] = {"./word_explorer", folder_path, word, NULL};
   // execvp(args[0], args);
    
    return 0;


}