/*
============================================================================
Name : 12.c
Author : Divy Pagariya
Description : Write a program to create an orphan process. Use kill system call to send SIGKILL signal to
the parent process from the child process.
Date: 18th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();

    if (pid > 0) {
        // Parent process: wait for a signal from the child
        sleep(10);
    } else if (pid == 0) {
        // Child process: send SIGKILL to the parent process
        printf("Child process is sending SIGKILL to parent process.\n");
        kill(getppid(), SIGKILL);
        sleep(5);  // Give time to observe the orphaned process
        printf("Child process is now an orphan (adopted by init).\n");
    } else {
        printf("Fork failed!\n");
    }

    return 0;
}
