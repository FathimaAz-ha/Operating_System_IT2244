/*1)Write a C program that creates two threads. Each thread should print a message indicating it is running. The main thread should wait for both threads to finish before exiting.*/


#include <stdio.h>
#include <pthread.h>

//thread function 1
void* threadFunction1(void* arg){
printf("Thread 1 is running\n");
return NULL;
}

//thread function 2
void* threadFunction2(void* arg){
printf("thread 2 is running\n");
return NULL;
}

int main(){
pthread_t thread1, thread2;

//creating first thread
if(pthread_create(&thread1, NULL, threadFunction1, NULL) != 0 ){
perror("Failed to create thread 1");
return 1;
}

//create second thread
if(pthread_create(&thread2, NULL, threadFunction2, NULL) != 0 ){
perror("Failed to create thread 2");
return 1;

}
//waiting for both thread to be finished
pthread_join(thread1, NULL);
pthread_join(thread2, NULL);

printf("Main thread exiting after both threads finish\n");

return 0;

}
