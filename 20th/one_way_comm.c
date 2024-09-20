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
    mkfifo(fifo_path, 0666);

    int fd = open(fifo_path, O_WRONLY);
    for (int i = 0; i < 5; i++) {
        char message[20];
        sprintf(message, "Helllooo =  %d", i + 1);
        write(fd, message, sizeof(message));
        sleep(1);
    }
    close(fd);
    return 0;
}
