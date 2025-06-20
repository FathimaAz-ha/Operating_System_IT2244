/*5) Implement a thread function that takes an integer argument, squares it, and returns the result to the main thread using p_thread_exit and pthread_join*/
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void* square(void* arg) {
    int num = *(int*)arg;
    int* result = malloc(sizeof(int));
    *result = num * num;
    pthread_exit(result);
}

int main() {
    pthread_t thread;
    int input = 7;
    void* res;

    pthread_create(&thread, NULL, square, &input);
    pthread_join(thread, &res);

    printf("Square of %d is %d\n", input, *(int*)res);
    free(res);
    return 0;
}
