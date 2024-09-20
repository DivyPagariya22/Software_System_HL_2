/*
============================================================================
Name : 15.c
Author : Divy Pagariya
Description : Write a simple program to send some data from parent to the child process.
Date: 19th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include<string.h>

int main() {
    int pipefd[2];
    pid_t pid;
    const char *message = "Data from parent";
    char buffer[50];

    
    pipe(pipefd);

    pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        // Child process
        close(pipefd[1]); 
        read(pipefd[0], buffer, strlen(message) + 1); 
        printf("Child received: %s\n", buffer);
        close(pipefd[0]); 
    } else {
        close(pipefd[0]); 
        write(pipefd[1], message, strlen(message) + 1); 
        close(pipefd[1]);
    }

    return 0;
}
