/**************************************************************************************************
 Name        : Question15.c
 Author      : Youssef Nashaat
 Created on	 : Aug 24, 2022
 Description : Assignment 3 - Question 15
 **************************************************************************************************/
#include <stdio.h>

void concactenate(char *str1, char *str2);

int main(void)
{
	char str1[20] = "Hello";
	char str2[] = " World";


	printf("String 1 is: %s\n", str1);
	printf("String 2 is: %s\n", str2);
	concactenate(str1, str2);
	printf("Concatenated string is: %s\n", str1);

	return 0;
}


void concactenate(char *str1, char *str2)
{
	int i;
	for(i = 0 ; str1[i] != '\0' ; i++);

	while(*str2 != '\0')
	{
		str1[i] = *str2;
		i++;
		str2++;
	}
}
