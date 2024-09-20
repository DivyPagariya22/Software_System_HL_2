/*
============================================================================
Name : 26.c
Author : Divy Pagariya
Description : Write a program to send messages to the message queue. Check $ipcs -q
Date: 19th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

struct msg_buffer {
    long msg_type;
    char msg_text[100];
};

int main() {
    key_t key = ftok("key.txt", 65);
    int msgid = msgget(key, 0666 | IPC_CREAT);

    struct msg_buffer message;
    message.msg_type = 1;

    printf("Enter a message: ");
    fgets(message.msg_text, strlen(message.msg_text), stdin);

    msgsnd(msgid, &message, strlen(message.msg_text), 0);

    printf("Message sent to the queue.\n");

    return 0;
}
