/*
============================================================================
Name : 22.c
Author : Divy Pagariya
Description : Write a program to wait for data to be written into FIFO within 10 seconds, use select
system call with FIFO.
Date: 19th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/select.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
int main() {
    const char *fifo_path = "my_fifo";
    mkfifo(fifo_path, 0666);

    int fd = open(fifo_path, O_RDONLY | O_NONBLOCK);


    fd_set readfds;
    FD_ZERO(&readfds);
    FD_SET(fd, &readfds);

    struct timeval timeout;
    timeout.tv_sec = 10;   
    timeout.tv_usec = 0;

    int ret = select(fd + 1, &readfds, NULL, NULL, &timeout);
    
    if (ret == -1) {
        perror("select");
    } else if (ret == 0) {
        printf("Timeout occurred!\n");
    } else {
        if (FD_ISSET(fd, &readfds)) {
            char buffer[100];
            int bytes_read = read(fd, buffer, strlen(buffer) + 1);
            if (bytes_read > 0) {
                buffer[bytes_read] = '\0';
                printf("Received: %s\n", buffer);
            }
        }
    }

    close(fd);
    return 0;
}
