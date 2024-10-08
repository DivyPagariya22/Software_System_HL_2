/*
============================================================================
Name : 1c.c
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

void handle_prof_signal(int signum) {
    printf("Prof timer expired\n");
}

int main() {
    struct itimerval prof_timer;

    signal(SIGPROF, handle_prof_signal);

    prof_timer.it_value.tv_sec = 10;
    prof_timer.it_value.tv_usec = 500000;
    prof_timer.it_interval.tv_sec = 10;
    prof_timer.it_interval.tv_usec = 500000;

    if (setitimer(ITIMER_PROF, &prof_timer, NULL) == -1) {
        perror("Prof timer error");
        exit(EXIT_FAILURE);
    }

    while (1) {
        // Simulate CPU-bound work
    }

    return 0;
}
