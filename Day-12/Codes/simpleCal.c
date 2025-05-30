#include <stdio.h>

int main(){
int num1;
printf("Enter number 1:");
scanf("%d", &num1);

int num2;
printf("Enter number 2 : ");
scanf("%d", &num2);

int add=num1+num2;
printf("Addition :  %d\n", add);
int sub=num1-num2;
printf("Substraction : %d\n ", sub);
int mul=num1*num2;
printf("Multiplication : %d\n", mul);
int div=num1/num2;
printf("Division : %d\n", div);
int rem=num1%num2;
printf("Remainder : %d\n", rem);
return 0;
}
// This program performs basic arithmetic operations (addition, subtraction, multiplication, division, and remainder) on two integers input by the user.
// It prompts the user to enter two numbers, performs the calculations, and prints the results.