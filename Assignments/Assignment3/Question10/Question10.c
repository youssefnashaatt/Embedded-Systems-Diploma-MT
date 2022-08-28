/**************************************************************************************************
 Name        : Question10.c
 Author      : Youssef Nashaat
 Created on	 : Aug 23, 2022
 Description : Assignment 3 - Question 10
 **************************************************************************************************/
#include <stdio.h>

void lowercase(char *str);

int main(void)
{
	char string_input[] = "HeLlo";
	lowercase(string_input);

	printf("%s", string_input);

	return 0;
}


void lowercase(char *str)
{
	while(*str != '\0')
	{
		if(*str >= 'A' && *str <= 'Z')
		{
			*str += 32;
		}

		str++;
	}
}

