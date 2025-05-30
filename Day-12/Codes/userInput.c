#include <stdio.h>
int main(){
int age;
printf("Enter your age : ");
scanf("%d", &age); //&-ampason

printf("Age:%d\n", age);

double number;
char alpha;
printf("Enter double input : ");
scanf("%lf", &number);
printf("\nYour number is : %lf\n", number);

printf("Enter character ");
scanf(" %c", &alpha);
printf("\nYour character :%c ", alpha);


double n1;
char s;
printf("Enter inputs : ");
scanf("%lf %c", &n1,&s);
printf("\nYour outputs : %lf %c\n", n1,s);

}
// Note: When using scanf for characters, a space before %c is often used to consume any leftover newline character from previous inputs.
// This ensures that the character input is read correctly without being affected by any previous input.