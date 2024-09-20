/*
============================================================================
Name : 10b.c
Author : Divy Pagariya
Description : Write a separate program using sigaction system call to catch the following signals.
b. SIGINT
Date: 17th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handle_sigint(int signum) {
    printf("Caught SIGINT (interrupt from keyboard)\n");
    exit(0);
}

int main() {
    struct sigaction sa;
    sa.sa_handler = handle_sigint;
    sigaction(SIGINT, &sa, NULL);

    while (1); 

    return 0;
}
