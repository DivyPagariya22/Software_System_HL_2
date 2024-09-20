/*
============================================================================
Name : 19d.c
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
#include <sys/stat.h>

int main() {
    if (mkfifo("my_fifo_using_mkfifo_syscall", 0666) == -1) {
        perror("mkfifo error");
        return 1;
    }
    return 0;
}
