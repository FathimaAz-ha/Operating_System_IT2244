/*4) Create two threads where one thread increments a global counter 100 times and other thread decrements the same counter 100 times. Print the final value of the counter after both thread finish.*/

#include <stdio.h>
#include <pthread.h>

int counter = 0;
pthread_mutex_t lock;

void* increment(void* arg) {
    for (int i = 0; i < 100; ++i) {
        pthread_mutex_lock(&lock);
        counter++;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

void* decrement(void* arg) {
    for (int i = 0; i < 100; ++i) {
        pthread_mutex_lock(&lock);
        counter--;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main() {
    pthread_t inc_thread, dec_thread;
    pthread_mutex_init(&lock, NULL);

    pthread_create(&inc_thread, NULL, increment, NULL);
    pthread_create(&dec_thread, NULL, decrement, NULL);

    pthread_join(inc_thread, NULL);
    pthread_join(dec_thread, NULL);

    printf("Final counter value: %d\n", counter);
    pthread_mutex_destroy(&lock);
    return 0;
}

