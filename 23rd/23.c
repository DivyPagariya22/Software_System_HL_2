/*
============================================================================
Name : 23.c
Author : Divy Pagariya
Description : This program prints the maximum number of files that can be opened 
              within a process and the size of a pipe (circular buffer).
Date: 19th Sep, 2024.
============================================================================
*/


#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Maximum number of open files =>  %ld\n", sysconf(_SC_OPEN_MAX));
    printf("Pipe size is =>  %ld bytes\n", fpathconf(STDIN_FILENO, _PC_PIPE_BUF));

    return 0;
}