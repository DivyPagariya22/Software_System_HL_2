/*
============================================================================
Name : 6.c
Author : Divy Pagariya
Description : Write a simple program to create three threads.
Date: 17th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <pthread.h>

void* thread_function(void* arg) {
    printf("Thread %ld\n", (long)arg);
    return NULL;
}

int main() {
    pthread_t threads[3];

    for (long i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, thread_function, (void*)i);
    }

    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
