/*
============================================================================
Name : 8a.c
Author : Divy Pagariya
Description : Write a separate program using signal system call to catch the following signals.
        a. SIGSEGV
Date: 17th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handle_sigsegv(int sig) {
    printf("Caught SIGSEGV (segmentation fault)\n");
    exit(1);
}

int main() {
    signal(SIGSEGV, handle_sigsegv);
    int *p = NULL;
    *p = 42; // Trigger SIGSEGV

    return 0;
}
