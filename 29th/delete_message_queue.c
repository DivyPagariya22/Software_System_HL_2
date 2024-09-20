/*
============================================================================
Name : 29.c
Author : Divy Pagariya
Description : Write a program to remove the message queue.
Date: 19th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
    key_t key = ftok("key", 65);
    int msgid = msgget(key, 0666);

    
    if (msgctl(msgid, IPC_RMID, NULL) == -1) {
        perror("msgctl IPC_RMID failed");
        return 1;
    }

    printf("Message queue removed successfully.\n");
    return 0;
}
