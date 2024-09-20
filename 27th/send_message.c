/*
============================================================================
Name : 27.c
Author : Divy Pagariya
Description : Write a program to receive messages from the message queue.
a. with 0 as a flag
b. with IPC_NOWAIT as a flag
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
    key_t key = ftok("progfile", 65);
    int msgid = msgget(key, 0666 | IPC_CREAT);

    struct msg_buffer message;
    message.msg_type = 1; // Set the message type

    while (1) {
        printf("Enter a message (or type 'exit' to quit): ");
        fgets(message.msg_text, sizeof(message.msg_text), stdin);

        // Remove newline character from fgets input
        message.msg_text[strcspn(message.msg_text, "\n")] = 0;

        // Check for exit condition
        if (strcmp(message.msg_text, "exit") == 0) {
            break;
        }

        msgsnd(msgid, &message, sizeof(message.msg_text), 0);
        printf("Message sent to the queue.\n");
    }

    return 0;
}
