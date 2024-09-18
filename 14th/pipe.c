/*
============================================================================
Name : 14.c
Author : Divy Pagariya
Description : Write a simple program to create a pipe, write to the pipe, read from pipe and display on
the monitor.
Date: 19th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pipefd[2];
    char buffer[100];
    const char *message = "Hello, Pipe!";

    pipe(pipefd);

    if (fork() == 0) {
        close(pipefd[0]);
        write(pipefd[1], message, strlen(message) + 1);
        close(pipefd[1]);
    } else {
        close(pipefd[1]);
        read(pipefd[0], buffer, strlen(message) + 1);
        printf("Message from pipe: %s\n", buffer);
        close(pipefd[0]);
    }

    return 0;
}
