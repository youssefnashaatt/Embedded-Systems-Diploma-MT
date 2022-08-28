#include <stdio.h>
#include <math.h>

int main(void)
{
	int N;
	double result;

	printf("Please enter a number: ");
	fflush(stdout);

	scanf("%d", &N);

	result = sqrt(N);

	if (result - (int)result == 0)
	{
		printf("The number is perfect square.");
	}

	else
	{
		printf("The number isn't perfect square.");
	}


}
