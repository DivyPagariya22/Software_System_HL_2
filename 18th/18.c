/*
============================================================================
Name : 18.c
Author : Divy Pagariya
Description : Write a program to find out total number of directories on the pwd.
execute ls -l | grep ^d | wc ? Use only dup2.
Date: 19th Sep, 2024.
============================================================================
*/

// Not Woking 

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pipefd1[2], pipefd2[2];
    pipe(pipefd1);
    pipe(pipefd2);

    if (fork() == 0) {
        close(pipefd1[0]);
        dup2(pipefd1[1], STDOUT_FILENO);
        close(pipefd1[1]);
        execlp("ls", "ls", "-l", NULL);
        _exit(1);
    }

    if (fork() == 0) {
        close(pipefd1[1]);
        dup2(pipefd1[0], STDIN_FILENO);
        close(pipefd1[0]);
        dup2(pipefd2[1], STDOUT_FILENO);
        close(pipefd2[1]);
        execlp("grep", "grep", "HL_List_2", NULL);
        _exit(1);
    }

    if (fork() == 0) {
        close(pipefd1[0]);
        close(pipefd1[1]);
        close(pipefd2[1]);
        dup2(pipefd2[0], STDIN_FILENO);
        close(pipefd2[0]);
        execlp("wc", "wc", "-l", NULL);
        _exit(1);
    }

    close(pipefd1[0]);
    close(pipefd1[1]);
    close(pipefd2[0]);
    close(pipefd2[1]);

    wait(NULL);
    wait(NULL);
    wait(NULL);

    return 0;
}
