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
    mkfifo(fifo_to_child, 0666);
    mkfifo(fifo_to_parent, 0666);

    char write_msg[20], read_msg[20];

    // Sending message to child
    int fd_write = open(fifo_to_child, O_WRONLY);
    sprintf(write_msg, "Hello Child!");
    write(fd_write, write_msg, strlen(write_msg));
    close(fd_write);

    // Receiving response from child
    int fd_read = open(fifo_to_parent, O_RDONLY);
    read(fd_read, read_msg, strlen(read_msg));
    printf("Received from Child: %s\n", read_msg);
    close(fd_read);

    return 0;
}
