/*
============================================================================
Name : 30.c
Author : Divy Pagariya
Description : Write a program to create a shared memory.
a. write some data to the shared memory
b. attach with O_RDONLY and check whether you are able to overwrite.
c. detach the shared memory
d. remove the shared memory
Date: 19th Sep, 2024.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>

#define SIZE 1024

int main() {
    key_t key = ftok("key", 65);
    int shmid = shmget(key, SIZE, IPC_CREAT | 0666);

    if (shmid < 0) {
        perror("shmget failed");
        return 1;
    }

    char *str = (char *)shmat(shmid, NULL, 0);
    if (str == (char *)(-1)) {
        perror("shmat failed");
        return 1;
    }


    strcpy(str, "Hello, Shared Memory!");

   
    shmdt(str);

 
    str = (char *)shmat(shmid, NULL, SHM_RDONLY);
    if (str == (char *)(-1)) {
        perror("shmat failed");
        return 1;
    }

    // If overwrite Segmentaion Fault comes !

    printf("Data in shared memory: %s\n", str);

    shmdt(str);

    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}
