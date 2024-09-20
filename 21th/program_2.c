/*
============================================================================
Name : 21.c
Author : Divy Pagariya
Description : Write two programs so that both can communicate by FIFO -Use two way communications.
Date: 19th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

int main() {
    const char *fifo_to_child = "my_fifo";
    const char *fifo_to_parent = "my_fifo_2";
    char write_msg[20], read_msg[20];

    // Receiving message from parent
    int fd_read = open(fifo_to_child, O_RDONLY);
    read(fd_read, read_msg, sizeof(read_msg));
    printf("Received from Parent: %s\n", read_msg);
    close(fd_read);

    // Sending response to parent
    int fd_write = open(fifo_to_parent, O_WRONLY);
    sprintf(write_msg, "Hello Parent!");
    write(fd_write, write_msg, sizeof(write_msg));
    close(fd_write);

    return 0;
}
