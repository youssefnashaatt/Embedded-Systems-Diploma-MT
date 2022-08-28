/**************************************************************************************************
 Name        : Question19.c
 Author      : Youssef Nashaat
 Created on	 : Aug 19, 2022
 Description : Assignment 2 - Question 19
 **************************************************************************************************/
#include <stdio.h>
#include <math.h>

int power_of_three(int integer)
{
	if((integer == 1) || (integer == 0))
		return 1;

	while(1)
	{
		if((integer % 3) == 0)
		{
			if(integer == 3)
			{
				return 0;
			}

			integer /= 3;
		}

		else
			return 1;
	}
}


int main(void)
{
	printf("%d\n", power_of_three(27));
	printf("%d\n", power_of_three(15));

	return 0;
}

