/*
============================================================================
Name : 33.c
Author : Divy Pagariya
Description : Write a program to communicate between two machines using socket.
Date: 19th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    char buffer[BUFFER_SIZE] = {0};

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    listen(server_fd, 1);
    
    new_socket = accept(server_fd, NULL, NULL);
    read(new_socket, buffer, BUFFER_SIZE);
    printf("Received: %s\n", buffer);
    send(new_socket, "Hello from server", 17, 0);
    
    close(new_socket);
    close(server_fd);
    return 0;
}
