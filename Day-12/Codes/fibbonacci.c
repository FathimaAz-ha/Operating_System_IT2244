#include<stdio.h>
int main(){
	int num;
	printf("Enter number: ");
	scanf("%d", &num);
	
	int x=0;
	int y=1;
	
	for(int i=1; i<=num; i++){
		printf("%d ",x);
		int z = x+y;
		x = y;
		y = z;
	}
	printf("\n");
return 0;
}
