#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
    int f = fork(); // create B

    if (f == 0) {
        // Only in B
        printf("\nI'm B\n");
        printf("My ppid: %d\n", getppid());
        printf("My pid: %d\n", getpid());
    } else {
        // Only in A
        int k = fork(); // create C
        if (k == 0) {
            // Only in C
            printf("\nI'm c\n");
            printf("My ppid: %d\n", getppid());
            printf("My pid: %d\n", getpid());
        } else {
            // Still A
            wait(NULL);
            wait(NULL);
            printf("\nI'm A\n");
            printf("My pid: %d\n", getpid());
        }
    }

    return 0;
}