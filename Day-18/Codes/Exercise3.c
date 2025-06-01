#include<stdio.h>
#include<unistd.h>//sleep,fork
#include<stdlib.h>//exit
#include<sys/wait.h>//for wait


int main(){
	pid_t pid;//a data type for initialize a pid
	
	printf("Parent process started. PID: %d\n",getpid());
	
	pid = fork();//create new child
	
	if(pid<0){
		perror("fork faild");
		exit(1);
	}
	if(pid==0){
		//child
		printf("Child process. PID: %d, Sleeping for 2 sec...\n",getpid());
		sleep(2);
		printf("Child process exiting.\n");
		exit(0);//child exits with status 0
	}
	else{
		//parent process
		int status;
		printf("Parent waiting for child to finish...\n");
		wait(&status);//wait for child to finish
		if(WIFEXITED(status)){ //return true if the child terminate normally
			printf("Child exited with status: %d\n",WEXITSTATUS(status));// gets the actual exit code (0 here)
		}
		else{
			printf("Child did not exit normaly.\n");
		}
		printf("Parent process ending.\n");
	}
	
	return 0;
}