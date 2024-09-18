/*
============================================================================
Name : 7.c
Author : Divy Pagariya
Description : Write a simple program to create three threads and print 
              their IDs.
Date: 17th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <pthread.h>

void* thread_function(void* arg) {
    pthread_t thread_id = pthread_self();
    printf("Thread ID: %lu\n", (unsigned long)thread_id);
    return NULL;
}

int main() {
    pthread_t threads[3];

    for (int i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, thread_function, NULL);
    }

    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
