/*
============================================================================
Name : 16.c
Author : Divy Pagariya
Description : Write a program to send and receive data from parent to child vice versa. Use two way
    communication.
Date: 19th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int parent_to_child[2], child_to_parent[2];
    pid_t pid;

    char parent_message[] = "Hello from parent";
    char child_message[] = "Hello from child";
    char buffer[50];


    pipe(parent_to_child);
    pipe(child_to_parent);

    pid = fork();

    if (pid == 0) {
        close(parent_to_child[1]);
        close(child_to_parent[0]);

        read(parent_to_child[0], buffer, strlen(buffer) + 1);
        printf("Child received: %s\n", buffer);

        write(child_to_parent[1], child_message, strlen(child_message) + 1);

        close(parent_to_child[0]);
        close(child_to_parent[1]);
    } else {
        close(parent_to_child[0]);
        close(child_to_parent[1]);

        write(parent_to_child[1], parent_message, strlen(parent_message) + 1);
        read(child_to_parent[0], buffer, strlen(buffer) + 1);
        
        printf("Parent received: %s\n", buffer);
        close(parent_to_child[1]);
        close(child_to_parent[0]);
    }

    return 0;
}
