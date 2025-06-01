#include<stdio.h>
#include<unistd.h>//sleep,fork
#include<stdlib.h>//exit


int main(){
	printf("Program started. \n");
	
	printf("Sleeping for 3 seconds... \n");
	sleep(3); //pause for 3 sec
	
	printf("Exiting the program. \n");
	exit(0); //clean exit
	
	return 0;
}