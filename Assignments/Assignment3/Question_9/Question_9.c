/**************************************************************************************************
 Name        : Question_9.c
 Author      : Youssef Nashaat
 Created on	 : Aug 23, 2022
 Description : Assignment 3 - Question 9
 **************************************************************************************************/
#include <stdio.h>

int fibonacci(int order);

int main(void)
{
	printf("Fibonacci(4) is equals to %d\n", fibonacci(4));
	printf("Fibonacci(7) is equals to %d\n", fibonacci(7));
	printf("Fibonacci(0) is equals to %d\n", fibonacci(0));
	printf("Fibonacci(1) is equals to %d\n", fibonacci(1));



	return 0;
}



int fibonacci(int order)
{
	int i = 1;
	int previous, previous_previous;
	int result;

	if(order == 0)
		return 1;

	while(i < order + 1)
	{
		if(i == 1)
		{
			result = 1;
			previous = 1;
			i++;
			continue;
		}


		previous_previous = previous;
		previous = result;
		result = previous_previous + previous;
		i++;
	}

	return result;
}

