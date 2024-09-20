/*
============================================================================
Name : 32.c
Author : Divy Pagariya
Description : Write a program to implement semaphore to protect any critical section.
a. rewrite the ticket number creation program using semaphore
b. protect shared memory from concurrent write access
c. protect multiple pseudo resources ( may be two) using counting semaphore
d. remove the created semaphore.
Date: 19th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_TICKETS 5

sem_t ticket_sem;

void *create_tickets(void *arg) {
    for (int i = 0; i < NUM_TICKETS; i++) {
        sem_wait(&ticket_sem);
        printf("Ticket number: %d\n", i + 1);
        sem_post(&ticket_sem);
        sleep(1);
    }
    return NULL;
}

int main() {
    sem_init(&ticket_sem, 0, 1);
    
    pthread_t ticket_thread1, ticket_thread2;
    pthread_create(&ticket_thread1, NULL, create_tickets, NULL);
    pthread_create(&ticket_thread2, NULL, create_tickets, NULL);

    pthread_join(ticket_thread1, NULL);
    pthread_join(ticket_thread2, NULL);

    sem_destroy(&ticket_sem);
    return 0;
}
