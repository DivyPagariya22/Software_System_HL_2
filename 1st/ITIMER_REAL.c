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
