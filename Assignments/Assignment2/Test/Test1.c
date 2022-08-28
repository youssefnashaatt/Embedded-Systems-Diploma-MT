/**************************************************************************************************
 Name        : Test1.c
 Author      : Youssef Nashaat
 Created on	 : Aug 19, 2022
 Description : 
 **************************************************************************************************/
#include <stdio.h>

float calc(char operation, float num1, float num2)
{
	switch(operation)
	{
	case '+':
		return num1 + num2;
		break;

	case '-':
		return num1 - num2;
		break;

	case '*':
		return num1 * num2;
		break;

	case '/':
		return num1 / num2;
		break;

	default:
		printf("ERROR!");
		return 0;
	}
}

int main(void)
{
	float x, y, result;
	char operation;

	printf("INPUT1:");
	fflush(stdout);
	scanf("%f", &x);

	printf("INPUT2:");
	fflush(stdout);
	scanf("%f", &y);

	printf("OPERATION( +, -, *, /):");
	fflush(stdout);
	scanf(" %c", &operation);

	result = calc(operation, x, y);

	printf("%.2f", result);

	return 0;
}

