/**************************************************************************************************
 Name        : Question8.c
 Author      : Youssef Nashaat
 Created on	 : Aug 13, 2022
 Description : Assignment 2 - Question8
 **************************************************************************************************/
#include <stdio.h>

#define TRUE 1
#define FALSE 0

//Function Declaration
void display_prime (int, int);
int check_prime(int);


int main(void)
{
	int num1, num2;

	printf("Please enter two numbers:\n");
	fflush(stdout);
	scanf("%d %d", &num1, &num2);

	display_prime(num1, num2);

	return 0;
}


void display_prime (int num1, int num2)
{


	if (num1 > num2)
	{
		int temp = num1;
		num1 = num2;
		num2 = temp;
	}


	for (int i = num1 ; i < num2; i++)
	{
		if (check_prime(i) == TRUE)
			printf("%d is prime number\n", i);
	}
}


int check_prime(int integer)
{
	for (int i = (integer - 1) ; i > 1 ; i--)
	{
		if (integer % i == 0)
			return FALSE;
	}

	return TRUE;
}








