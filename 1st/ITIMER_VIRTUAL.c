/*
============================================================================
Name : 1b.c
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

void handle_virt_signal(int signum) {
    printf("Virtual timer expired\n");
}

int main() {
    struct itimerval virt_timer;
    
    signal(SIGVTALRM, handle_virt_signal);

    virt_timer.it_value.tv_sec = 10;
    virt_timer.it_value.tv_usec = 500000;
    virt_timer.it_interval.tv_sec = 10;
    virt_timer.it_interval.tv_usec = 500000;

    if (setitimer(ITIMER_VIRTUAL, &virt_timer, NULL) == -1) {
        perror("Virtual timer error");
        exit(EXIT_FAILURE);
    }

    while (1) {}

    return 0;
}
