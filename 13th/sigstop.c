/*
============================================================================
Name : 13.c
Author : Divy Pagariya
Description : Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.
Date: 18th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_signal(int sig) {
    printf("Caught signal: %d\n", sig);
}

int main() {
    struct sigaction sa;
    sa.sa_handler = handle_signal;
    sigaction(SIGSTOP, &sa, NULL);  // Trying to catch SIGSTOP
    printf("Process PID: %d\n", getpid());
    printf("Waiting to catch SIGSTOP signal...\n");
    while (1) {
        pause();  // Waiting for signals
    }

    return 0;
}
