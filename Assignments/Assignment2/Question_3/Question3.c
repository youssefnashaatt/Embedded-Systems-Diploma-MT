#include <stdio.h>

//Function Declaration
int bool_check_positive (int);

int main(void)
{
	int number;

	printf("Please enter a number: ");
	fflush(stdout);
	scanf("%d", &number);

	if (bool_check_positive(number) == 1)
		printf("The number you've entered is positive.");

	else
		printf("The number you've entered is negative");
}


int bool_check_positive (int x)
{
	if (x >= 0)
		return 1;

	else
		return 0;
}
