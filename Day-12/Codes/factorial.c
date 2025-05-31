// Program to find factorial of a number
#include<stdio.h>
int main(){
	int num;
	printf("Enter number: ");
	scanf("%d", &num);
	
	int fac = 1;
	
	for(int i=1; i<=num; i++){
		fac*=i;
	}
	printf("Factorial of %d is: %d\n",num,fac);
return 0;
}