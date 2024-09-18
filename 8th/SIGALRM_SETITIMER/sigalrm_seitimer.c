/*
============================================================================
Name : 8e.c
Author : Divy Pagariya
Description :  Write a separate program using signal system call to catch the following signals.
e. SIGALRM (use setitimer system call)
Date: 17th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void handle_sigalrm(int sig) {
    printf("Caught SIGALRM (alarm clock) using setitimer\n");
}

int main() {
    struct itimerval timer;
    signal(SIGALRM, handle_sigalrm);

    timer.it_value.tv_sec = 1;  // Initial expiration
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;  // No repeat
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_REAL, &timer, NULL);

    pause(); // Wait for signals

    return 0;
}
