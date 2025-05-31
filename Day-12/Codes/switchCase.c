/*Syntax 
switch (exp){
case 1 :
//statement
break;

case2 : 
//statement
break;

...

default :

}
*/
#include <stdio.h>
int main()
{
	int number;
	printf("Enter a number to find the day : ");
	scanf("%d", &number);
	
	switch(number)
	{
	case 1 :
	printf("Sunday! its your day!\n");
	break;
	
	case 2 : 
	printf("Monday!, its your day!\n");
	break;
	
	case 3 : 
	printf("Tuesday !, its your day!\n");
	break;
	
	case 4 :
	printf("Wednesday!, its your day!\n");
	break;
	
	case 5 : 
	printf("Thursday!, its your day!\n");
	break;
	
	case 6 : 
	printf("Friday!, its your day!\n");
	break;
	
	case 7:
	printf("Saturday!, its your day!\n");
	break;
	
	default : 
	printf("oops sorry, Enter a number within 1 ot 7 !!");
	
	}
	
	
}

//04 - life path number
	int n;
	printf("Enter your birth date: ");
	scanf("%d",&n);
	
	int a=n%10;
	int b=n/10;
	int c=a+b;
	
	int x,y,z;
	
	if(c>9){
		x=c%10;
		y=c/10;
		z=x+y;
	}
	else{
		z=c;
	}
	
	switch(z){
		case 1:
			printf("Lucky\n");
			break;
		case 2:
			printf("Carefuly do your work\n");
			break;
		case 3:
			printf("Stronger\n");
			break;
		case 4:
			printf("Happy\n");
			break;
		case 5:
			printf("Can get help\n");
			break;
		case 6:
			printf("Doubt\n");
			break;
		case 7:
			printf("Sad\n");
			break;
		case 8:
			printf("Like\n");
			break;
		case 9:
			printf("Courage\n");
			break;
		default:
			printf("Invalid nmuber!\n");	
	}

