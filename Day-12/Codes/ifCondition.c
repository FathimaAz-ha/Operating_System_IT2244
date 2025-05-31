/*if(condition) {
			//body of if statement
			}
			else {
			//body for else statement
			}

Example : Enter user age and check whether he/she is eligible for vote or not*/
#include <stdio.h>
int main()
{
int age;
printf("Enter your age : ");
scanf("%d", &age);
if(age < 0){
printf("\nInvalid Input\n");
}
else if(age>=18)
{
printf("you are eligible for voting!\n");
}
else{
printf("You are not an elder!\n");
}
return 0;
}

/*
TernaryOperator syntax: 
(test_condition) ? expression1 : expression 2;

(age>=18) ? printf("You are eligible for voting!"): printf("you are a child!")

*/