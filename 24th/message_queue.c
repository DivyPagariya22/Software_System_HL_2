/*
============================================================================
Name : 24.c
Author : Divy Pagariya
Description : Write a program to create a message queue and print the key and message queue id.
Date: 19th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
    key_t key = ftok("key.txt", 65);
    int msgid = msgget(key, 0666 | IPC_CREAT);
    printf("Key: %d\n", key);
    printf("Message Queue ID: %d\n", msgid);
    return 0;
}
