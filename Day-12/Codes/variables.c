#include <stdio.h>

int main(){
int age=25;
printf("%d\n",age);

printf("C programming");

//updating the variable
age=31;
printf("\nNew age:%d\n",age);


//changing one variable to another

int firstNumber=25;
printf("First Number is :%d\n ", firstNumber);

int secondNumber=firstNumber;
printf("Second Number : %d\n", secondNumber);


int a,b=0;
printf("a : %d", a,b);

//initializing multiple variables in same line- int firstNumber, secondNumber=25;
int firstNumber1, secondNumber1=25;
printf("First Number1 is :%d\n ", firstNumber1);

return 0;
}