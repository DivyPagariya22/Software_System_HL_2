/*
============================================================================
Name : catch_sigvtalrm_setitimer.c
Author : Divy Pagariya
Description :  Write a separate program using signal system call to catch the following signals.
f. SIGVTALRM (use setitimer system call)
g. SIGPROF (use setitimer system call)
Date: 17th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void handle_sigvtalrm(int sig) {
    printf("Caught SIGVTALRM (virtual timer) using setitimer\n");
}

int main() {
    struct itimerval timer;
    signal(SIGVTALRM, handle_sigvtalrm);

    timer.it_value.tv_sec = 1;  // Initial expiration
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;  // No repeat
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_VIRTUAL, &timer, NULL);

    pause(); // Wait for signals

    return 0;
}
