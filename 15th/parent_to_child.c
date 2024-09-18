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

    // Create a pipe
    pipe(pipefd);

    // Fork a new process
    pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        // Child process
        close(pipefd[1]); // Close the write end of the pipe
        read(pipefd[0], buffer, strlen(message) + 1); // Read from the pipe
        printf("Child received: %s\n", buffer);
        close(pipefd[0]); // Close the read end of the pipe
    } else {
        // Parent process
        close(pipefd[0]); // Close the read end of the pipe
        write(pipefd[1], message, strlen(message) + 1); // Write to the pipe
        close(pipefd[1]); // Close the write end of the pipe
    }

    return 0;
}
