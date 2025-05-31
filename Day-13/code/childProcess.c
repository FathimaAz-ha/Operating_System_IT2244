#include<stdio.h>
#include<unistd.h>
int main(){
printf("\nHello World!\n");
int f = fork();
if(f==0){
printf("\nI'm child process!\n");
}
else{
printf("\nI'm parent process\n");
}
return 0;
}