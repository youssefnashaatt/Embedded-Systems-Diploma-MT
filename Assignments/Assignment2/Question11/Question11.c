/**************************************************************************************************
 Name        : Question11.c
 Author      : Youssef Nashaat
 Created on	 : Aug 13, 2022
 Description : Assignment 2 - Question 11
 **************************************************************************************************/
#include <stdio.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

//Functions Declaration
int power_of_two(float number);


int main(void)
{
	float number;

	do
	{
	printf("Please enter a positive integer: ");
	fflush(stdout);
	scanf("%f", &number);
	}

	while (number < 0);


	if (power_of_two(number) == TRUE)
		printf("The number is perfect square.\n");

	else
		printf("The number isn't perfect square.\n");
}


int power_of_two(float number)
{
	if ((sqrt(number) - (int)sqrt(number)) == 0)
		return TRUE;

	else
		return FALSE;
}
