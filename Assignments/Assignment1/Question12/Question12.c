#include <stdio.h>


int main(void)
{

	int integer;
	int factorial = 1;


	do
	{
		printf("Please enter a valid positive number: ");
		fflush(stdout);
		scanf("%d", &integer);
	}

	while(integer < 0);


	for(int i = 1; i <= integer ; i++)
	{
		factorial = factorial * i;
	}


	printf("The factorial of %d is %d.", integer, factorial);

	return 0;
}

