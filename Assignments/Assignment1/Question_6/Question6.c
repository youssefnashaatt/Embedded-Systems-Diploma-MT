#include "stdio.h"

int main(void)
{
	//Variables declaration
	int num1, num2;

	printf("Please enter 2 numbers: ");
	fflush(stdout);
	scanf("%d %d", &num1, &num2);

	if (num1 == num2)
		printf("Both numbers are equal");

	else if (num1 > num2)
		printf("First Number is the bigger");

	else
		printf("Second Number is the bigger");

	return 0;
}
