/*
============================================================================
Name : 8d.c
Author : Divy Pagariya
Description : Write a separate program using signal system call to catch the following signals.
d. SIGALRM (use alarm system call)
Date: 17th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_sigalrm(int sig) {
    printf("Caught SIGALRM (alarm clock)\n");
}

int main() {
    signal(SIGALRM, handle_sigalrm);
    alarm(1); // Set an alarm for 1 second

    pause(); // Wait for signals

    return 0;
}
