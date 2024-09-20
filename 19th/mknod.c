/*
============================================================================
Name : 19c.c
Author : Divy Pagariya
Description : Create a FIFO file by
a. mknod command
b. mkfifo command
c. use strace command to find out, which command (mknod or mkfifo) is better.
c. mknod system call
d. mkfifo library function
Date: 19th Sep, 2024.
============================================================================
*/



#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    if (mknod("my_fifo_syscall", S_IFIFO | 0666, 0) == -1) {
        perror("mknod error");
        return 1;
    }
    return 0;
}
