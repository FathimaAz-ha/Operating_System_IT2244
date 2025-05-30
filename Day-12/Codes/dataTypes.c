#include <stdio.h>

int main(){

int age=10;
printf("%d\n",age);

printf("size: %zu\n", sizeof(age));

//double number
double number=12.45;
printf("%lf\n",number); //12.450000 6 bytes
printf("%.2lf\n", number); //prints with 2 decimal points

//floating number
float number1=10.9f;
printf("%f\n", number1);
printf("%.1f\n", number1); //with one decimal point

//char type
char character='z';
printf("%c", character);
printf("\n%d", character); //characters are in


return 0;
}
// ASCII format, so it prints the ASCII value of the character
// For 'z', it prints 122