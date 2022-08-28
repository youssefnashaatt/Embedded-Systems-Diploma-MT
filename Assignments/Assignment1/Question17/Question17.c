#include <stdio.h>


int main(void)
{
	int number, count = 0;

	printf("Please enter a number: ");
	fflush(stdout);
	scanf("%d", &number);

	int x = number;

	while(x != 0)
	{
		x /= 10;

		count++;
	}

	printf("The number of digits in %d is %d", number, count);

	return 0;
}
