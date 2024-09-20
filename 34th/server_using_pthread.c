/*
============================================================================
Name : 34a.c
Author : Divy Pagariya
Description : 34. Write a program to create a concurrent server.
a. use fork
b. use pthread_create
Date: 19th Sep, 2024.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080

void *handle_client(void *arg) {
    int client_socket = *(int *)arg;
    char buffer[1024];
    read(client_socket, buffer, sizeof(buffer));
    printf("Client: %s\n", buffer);
    send(client_socket, "Hi from server", 14, 0);
    close(client_socket);
    return NULL;
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    listen(server_fd, 3);

    while ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))) {
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, &new_socket);
        pthread_detach(thread_id);
    }
    return 0;
}
