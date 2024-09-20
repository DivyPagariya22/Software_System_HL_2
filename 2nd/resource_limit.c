/*
============================================================================
Name : 2.c
Author : Divy Pagariya
Description : Write a program to print the system resource limits. Use getrlimit system call.
Date: 17th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/resource.h>
#include <stdlib.h>

void print_limit(int resource, const char *name) {
    struct rlimit limit;

    if (getrlimit(resource, &limit) == 0) {
        printf("%s limits:\n", name);
        printf("Soft limit: %ld\n", (long)limit.rlim_cur);
        printf("Hard limit: %ld\n\n", (long)limit.rlim_max);
    } else {
        perror("Error getting limit");
    }
}

int main() {
    print_limit(RLIMIT_CPU, "CPU Time");
    print_limit(RLIMIT_FSIZE, "File Size");
    print_limit(RLIMIT_DATA, "Data Segment Size");
    print_limit(RLIMIT_STACK, "Stack Size");
    print_limit(RLIMIT_RSS, "Resident Set Size");
    print_limit(RLIMIT_NPROC, "Number of Processes");
    print_limit(RLIMIT_NOFILE, "Number of Open Files");
    print_limit(RLIMIT_MEMLOCK, "Locked Memory");
    print_limit(RLIMIT_AS, "Address Space");

    return 0;
}
