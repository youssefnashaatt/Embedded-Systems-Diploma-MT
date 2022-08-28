#include <stdio.h>

int Is_Prime(int integer);


int main(void)
{
	int integer;

	printf("Please enter a number: ");
	fflush(stdout);
	scanf("%d", &integer);

	if(Is_Prime(integer) == 0)
		printf("The number is not prime");

	else
		printf("The number is prime");

	return 0;

}



int Is_Prime(int integer)
{
	for (int i = integer - 1 ; i > 1 ; i--)
	{
		if ((integer % i) == 0)
		{
			return 0;	// The number is not prime
		}
	}

	return 1;	//The number is prime
}
