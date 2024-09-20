/*
============================================================================
Name : 17a.c
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

int main() {
    int pipefd[2];
    pipe(pipefd);

    if (fork() == 0) {
        dup(pipefd[1]);
        close(pipefd[0]);
        execlp("ls", "ls", "-l", NULL);
        
    } else {
        dup(pipefd[0]);
        close(pipefd[1]);
        execlp("wc", "wc", NULL);
        
    }

    return 0;
}
