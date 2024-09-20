/*
============================================================================
Name : 3.c
Author : Divy Pagariya
Description : Write a program to set (any one) system resource limit. Use setrlimit system call.
Date: 17th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/resource.h>
#include <stdlib.h>

int main() {
    struct rlimit limit;

    limit.rlim_cur = 1024;  // New soft limit
    limit.rlim_max = 2048;  // New hard limit

    if (setrlimit(RLIMIT_NOFILE, &limit) == 0) {
        printf("New limits set: Soft limit = %ld, Hard limit = %ld\n", (long)limit.rlim_cur, (long)limit.rlim_max);
    } else {
        perror("Error setting limit");
        exit(EXIT_FAILURE);
    }

    return 0;
}
