/*
============================================================================
Name : 25.c
Author : Divy Pagariya
Description : Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
a. access permission
b. uid, gid
c. time of last message sent and received
d. time of last change in the message queue
d. size of the queue
f. number of messages in the queue
g. maximum number of bytes allowed
h. pid of the msgsnd and msgrcv
Date: 19th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <time.h>

int main() {
    key_t key = ftok("key.txt", 65);
    int msgid = msgget(key, 0666 | IPC_CREAT);

    struct msqid_ds buf;
    msgctl(msgid, IPC_STAT, &buf);

    printf("Access permission: %o\n", buf.msg_perm.mode);

    printf("UID: %d, GID: %d\n", buf.msg_perm.uid, buf.msg_perm.gid);

    printf("Time of last message sent: %s", ctime(&buf.msg_stime));

    printf("Time of last message received: %s", ctime(&buf.msg_rtime));

    printf("Time of last change: %s", ctime(&buf.msg_ctime));

    printf("Size of the queue: %lu\n", buf.__msg_cbytes);

    printf("Number of messages in the queue: %lu\n", buf.msg_qnum);

    printf("Maximum number of bytes allowed: %lu\n", buf.msg_qbytes);

    printf("PID of last msgsnd: %d\n", buf.msg_lspid);


    printf("PID of last msgrcv: %d\n", buf.msg_lrpid);

    return 0;
}
