#include<stdio.h>
#include<unistd.h>
int main(){
printf("\nHello World!");
int f=fork();
int p=getpid();
printf("\nthe pid is %d",p);
printf("\nfork number %d\n",f);
return 0;
}