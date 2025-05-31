/*first child: sleep for 1 sec
second child: sleep for 3 sec
parent: both children have finished*/

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
int main(){
	pid_t pid;
	printf("Parent process started. PID: %d\n",getpid());
	pid = fork();
	
	if(pid<0){
		printf("Fork faild.\n");
		return 0;
	}
	if(pid==0){
		printf("Child process has started. Sleeping for 1 sec\nMy PID: %d\nMy PPID: %d\n",getpid(),getppid());
		sleep(1);
		printf("Child process 01 exiting...\n");
		return 0;
	}
	else{
		pid_t pid2;
		pid2 = fork();
		if(pid2<0){
			printf("Fork faild.\n");
			return 0;
		}
		if(pid2==0){
			printf("Child process has started. Sleeping for 3 sec\nMy PID: %d\nMy PPID: %d\n",getpid(),getppid());
			sleep(3);
			printf("Child process 02 exiting...\n");
			return 0;
		}
		else{
		//parent process
		wait(NULL);
		wait(NULL);
		printf("Parent process ending.\n");
		}
	}
	
	
	return 0;
}