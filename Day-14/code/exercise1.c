#include<stdio.h>
#include<unistd.h>
int main(){
	int n;
	int f = fork();
	if(f==0){
		n = 1;
	}
	else{
		n = 6;
	}
	
	int sum=0;
	for(int i=n; i<n+5; i++){
		printf("%d ", i);
		sum+=i;
	}
	printf("\nSummation : %d\n",sum);
		
	return 0;
}