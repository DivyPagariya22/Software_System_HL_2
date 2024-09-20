/*
============================================================================
Name : 10c.c
Author : Divy Pagariya
Description : Write a separate program using sigaction system call to catch the following signals.
c. SIGFPE
Date: 17th Sep, 2024.
============================================================================
*/


#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handle_sigfpe(int signum) {
    printf("Caught SIGFPE (floating-point exception)\n");
    exit(1);
}

int main() {
    struct sigaction sa;
    sa.sa_handler = handle_sigfpe;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    sigaction(SIGFPE, &sa, NULL);

    int a = 5;
    int b = 0;
    int c = a / b; 
    (void)c; 

    return 0;
}
