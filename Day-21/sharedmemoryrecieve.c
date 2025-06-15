//reader
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/shm.h>

# define SHM_SIZE 1024

int main(){
	
	key_t key=ftok("shmfile", 37); //generate unique key
	int shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);  //Access shared memory segment
	if(shmid == -1){
		perror("shmget");
		exit(1);
	}
	
	char *shmaddr = (char*) shmat(shmid,  NULL, 0); //Attach to shared memory
	if(shmaddr == (char*) -1){
		perror("shmat");
		exit(1);
	}
	
	printf("Data read from memory: %s\n", shmaddr); //read data from shared memory
	
	shmdt(shmaddr); //detach from shared memory
	
	shmctl(shmid, IPC_RMID, NULL); //remove shared memory segment
	
	return 0;
}


output:
[2021ict48@fedora ~]gcc shmreceive.c -o shmreceive
[2021ict48@fedora ~]$ ./shmreceive
Data read from memory: Fathima