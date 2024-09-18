/*
============================================================================
Name : 10a.c
Author : Divy Pagariya
Description : Write a separate program using sigaction system call to catch the following signals.
a. SIGSEGV
Date: 17th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handle_sigsegv(int signum) {
    printf("Caught SIGSEGV (segmentation fault)\n");
    exit(1);
}

int main() {
    struct sigaction sa;
    sa.sa_handler = handle_sigsegv;
    sigaction(SIGSEGV, &sa, NULL);

    int *ptr = NULL;
    *ptr = 42;  // Intentional segmentation fault to trigger SIGSEGV

    return 0;
}
