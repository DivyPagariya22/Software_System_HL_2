/*
============================================================================
Name : 20.c
Author : Divy Pagariya
Description : Write two programs so that both can communicate by FIFO -Use one way communication.
Date: 19th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main() {
    const char *fifo_path = "my_fifo";
    char buffer[20];

    int fd = open(fifo_path, O_RDONLY);
    for (int i = 0; i < 5; i++) {
        read(fd, buffer, sizeof(buffer));
        printf("Received: %s\n", buffer);
    }
    close(fd);
    return 0;
}
