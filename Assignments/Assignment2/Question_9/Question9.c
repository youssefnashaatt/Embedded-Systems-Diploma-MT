/**************************************************************************************************
 Name        : Question9.c
 Author      : Youssef Nashaat
 Created on	 : Aug 13, 2022
 Description : Assignment 2 - Question 9
 **************************************************************************************************/
#include <stdio.h>

void swap(int *num1, int *num2);

int main(void)
{
	int num1, num2;

	printf("Num1: ");
	fflush(stdout);
	scanf("%d", &num1);

	printf("Num2: ");
	fflush(stdout);
	scanf("%d", &num2);

	swap(&num1, &num2);

	printf("\n\nAfter swaping.\nNum1 is %d\nNum2 is %d", num1, num2);

	return 0;
}


void swap(int *num1, int *num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

