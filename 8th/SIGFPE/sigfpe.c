/*
============================================================================
Name : 8c.c
Author : Divy Pagariya
Description : Write a separate program using signal system call to catch the following signals.
c. SIGFPE
Date: 17th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handle_sigfpe(int sig) {
    printf("Caught SIGFPE (floating-point exception)\n");
    exit(1);
}

int main() {
    signal(SIGFPE, handle_sigfpe);
    int x = 1 / 0; // Trigger SIGFPE

    return 0;
}
