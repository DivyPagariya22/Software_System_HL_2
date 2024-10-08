/*
============================================================================
Name : 28.c
Author : Divy Pagariya
Description : Write a program to change the exiting message queue permission. (use msqid_ds structure)
Date: 19th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <stdlib.h>

int main() {
    key_t key = ftok("key", 65);
    int msgid = msgget(key, 0666);

    if (msgid == -1) {
        perror("msgget failed");
        return 1;
    }

    struct msqid_ds buf;

    if (msgctl(msgid, IPC_STAT, &buf) == -1) {
        perror("msgctl IPC_STAT failed");
        return 1;
    }

   
    printf("Current permissions: %o\n", buf.msg_perm.mode);


    buf.msg_perm.mode = 0644; // Set new permissions to rw-r--r--

    if (msgctl(msgid, IPC_SET, &buf) == -1) {
        perror("msgctl IPC_SET failed");
        return 1;
    }

    printf("Permissions changed to: %o\n", buf.msg_perm.mode);
    return 0;
}
