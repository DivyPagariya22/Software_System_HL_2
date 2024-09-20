/*
============================================================================
Name : 1a.c
Author : Divy Pagariya
Description : Write a separate program (for each time domain) to set a interval timer in 10sec and
10micro second
a. ITIMER_REAL
b. ITIMER_VIRTUAL
c. ITIMER_PROF
Date: 17th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <signal.h>
#include <unistd.h>

void call_signal(int signum) {
    printf("...ITIMER_REAL expired\n");
}

int main() {

    struct itimerval timer;

    signal(SIGALRM, call_signal);

    // For Ten Second
    timer.it_value.tv_sec = 10;
    timer.it_interval.tv_sec = 10;

    //For 10 microsecond
    // timer.it_value.tv_usec = 10;
    // timer.it_interval.tv_usec = 10;


    if (setitimer(ITIMER_REAL, &timer, NULL) == -1) {
        perror("Error setting ITIMER_REAL");
        exit(1);
    }


    while(1) {
        pause();
    }

    return 0;
}
