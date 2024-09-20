/*
============================================================================
Name : 31.c
Author : Divy Pagariya
Description : Write a program to create a semaphore and initialize value to the semaphore.
a. create a binary semaphore
b. create a counting semaphore
Date: 19th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    // Binary semaphore
    sem_t *binary_sem = sem_open("/binary_sem", O_CREAT, 0644, 1);
    if (binary_sem == SEM_FAILED) {
        perror("sem_open binary_sem failed");
        exit(EXIT_FAILURE);
    }

    // Counting semaphore
    sem_t *counting_sem = sem_open("/counting_sem", O_CREAT, 0644, 5);
    if (counting_sem == SEM_FAILED) {
        perror("sem_open counting_sem failed");
        sem_close(binary_sem);
        sem_unlink("/binary_sem");
        exit(EXIT_FAILURE);
    }

    printf("Binary semaphore initialized to 1.\n");
    printf("Counting semaphore initialized to 5.\n");

    // Clean up
    sem_close(binary_sem);
    sem_close(counting_sem);
    sem_unlink("/binary_sem");
    sem_unlink("/counting_sem");

    return 0;
}
