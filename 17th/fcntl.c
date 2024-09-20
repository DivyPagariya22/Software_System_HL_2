/*
============================================================================
Name : 17c.c
Author : Divy Pagariya
Description : Write a program to execute ls -l | wc.
a. use dup
b. use dup2
c. use fcntl
Date: 19th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int pipefd[2];
    pipe(pipefd);

    if (fork() == 0) {
        close(pipefd[0]);
        fcntl(pipefd[1], F_DUPFD, STDOUT_FILENO);
        close(pipefd[1]);
        execlp("ls", "ls", "-l", NULL);
    } else {
        close(pipefd[1]);
        fcntl(pipefd[0], F_DUPFD, STDIN_FILENO);
        close(pipefd[0]);
        execlp("wc", "wc", NULL);
    }

    return 0;
}
