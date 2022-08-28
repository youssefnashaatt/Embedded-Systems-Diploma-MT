/**************************************************************************************************
 Name        : Question14.c
 Author      : Youssef Nashaat
 Created on	 : Aug 19, 2022
 Description : Assignment 2 - Question 14
 **************************************************************************************************/
#include <stdio.h>


int fibonacci(int order)
{
	if(order == 0)
		return 0;

	else if(order == 1)
		return 1;


	return fibonacci(order - 1) + fibonacci(order - 2);
}


int main(void)
{
	printf("The fibonacci series is:\n");
	printf("%d", fibonacci(0));

	for(int i = 1; i < 11; i++)
		printf(", %d", fibonacci(i));


	return 0;
}
