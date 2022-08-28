/**************************************************************************************************
 Name        : Question12.c
 Author      : Youssef Nashaat
 Created on	 : Aug 24, 2022
 Description : Assignment 3 - Question 12
 **************************************************************************************************/
#include <stdio.h>

int string_length(char *str)
{
	int count = 0;

	while(*str != '\0')
	{
		count++;
		str++;
	}

	return count;
}

int main(void)
{
	char *str = "Hello World!";
	int count;

	count = string_length(str);

	printf("No of characters in (%s) is %d", str, count);

	return 0;

}

