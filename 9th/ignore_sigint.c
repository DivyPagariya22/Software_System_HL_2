/*
============================================================================
Name : 9.c
Author : Divy Pagariya
Description : Write a program to ignore a SIGINT signal then reset the default action of the SIGINT
              signal - Use signal system call.
Date: 17th Sep, 2024.
============================================================================
*/


#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
    struct sigaction sa_ignore, sa_default;

    sa_ignore.sa_handler = SIG_IGN;
    sigaction(SIGINT, &sa_ignore, NULL);
    printf("SIGINT signal is being ignored. Press Ctrl+C...\n");

    sleep(5);

    sa_default.sa_handler = SIG_DFL;
    sigaction(SIGINT, &sa_default, NULL);
    printf("SIGINT signal is reset to default behavior. Press Ctrl+C again...\n");


    sleep(5);

    return 0;
}

