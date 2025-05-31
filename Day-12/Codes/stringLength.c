/* Write a C program that:
Accepts two strings as input from the user.
Concatenates the two strings Displays the concatenated result.
*/
#include<stdio.h>
int main(){
	char str1[100],str2[100];
	printf("Enter string1: ");
	scanf("%s",&str1);
	printf("Enter string2: ");
	scanf("%s",&str2);
	printf("%s%s\n",str1,str2);
return 0;
}`