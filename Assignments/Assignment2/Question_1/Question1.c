#include <stdio.h>

//Functions Declaration
int cube (int number);

int main(void)
{
	int number;

	printf("Enter a number: ");
	fflush(stdout);
	scanf("%d", &number);

	int cubed_number = cube(number);

	printf("The cube of number %d is %d", number, cubed_number);

	return 0;
}


int cube (int number)
{
	int result = number;
	for (int i = 1 ; i < 3 ; i++)
	{
		result *= number;
	}

	return result;
}
