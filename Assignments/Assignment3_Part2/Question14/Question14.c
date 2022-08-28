/**************************************************************************************************
 Name        : Question14.c
 Author      : Youssef Nashaat
 Created on	 : Aug 24, 2022
 Description : Assignment 3 - Question 14
 **************************************************************************************************/
#include <stdio.h>
#include <string.h>

char string[20] = "Hello World";
char reversed[20];

void reverse_string(char *string);

int main(void)
{
	reverse_string(string);
	printf("string: %s\n", string);
	printf("reversed string: %s\n", reversed);

	return 0;
}


void reverse_string(char *string)
{
	int j = strlen(string) - 1;
	for(int i = 0 ; i < strlen(string) ; i++)
	{
		reversed[i] = string[j];
		j--;
	}
}
