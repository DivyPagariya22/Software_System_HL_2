/*
============================================================================
Name : 8b.c
Author : Divy Pagariya
Description : Write a separate program using signal system call to catch the following signals.
b. SIGINT

Date: 17th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handle_sigint(int sig) {
    printf("Caught SIGINT (interrupt from keyboard)\n");
    exit(0);
}

int main() {
    signal(SIGINT, handle_sigint);
    while (1) {
        // Infinite loop to keep the program running
    }
    return 0;
}
