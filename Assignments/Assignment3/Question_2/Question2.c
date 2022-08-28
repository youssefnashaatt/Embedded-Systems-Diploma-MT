/**************************************************************************************************
 Name        : Question2.c
 Author      : Youssef Nashaat
 Created on	 : Aug 20, 2022
 Description : Assignment 3 - Question 2
 **************************************************************************************************/
#include <stdio.h>

#define TRUE 1
#define FALSE 0

int check_duplicity (char *string)
{
	for(int i = 0 ; *(string + i) != '\0' ; i++)
	{
		for(int j = 0 ; (*(string + j) != '\0') ; j++)
		{
			if(i == j)
				continue;

			if(*(string + i) == *(string + j))
			{
				return FALSE;
			}
		}
	}

	return TRUE;
}


int main(void)
{
	char string1[] = "Hello";
	char string2[] = "Hola";

	printf("Checking duplicity for string1 %d\n", check_duplicity(string1));
	printf("Checking duplicity for string2 %d\n", check_duplicity(string2));

	return 0;
}
