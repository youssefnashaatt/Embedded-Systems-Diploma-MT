#include <stdio.h>

int reversing(int n);

int main(void)
{
	int number, reversed;

	printf("Please enter a number: ");
	fflush(stdout);
	scanf("%d", &number);

	reversed = reversing(number);

	printf("Reversed number is %d", reversed);
}


int reversing(int n)
{
	int remainder, result = 0;

	while (n != 0)
	{
		 remainder = n % 10;
		 result = result * 10 + remainder;

		 n /= 10;
	}

	return result;
}
