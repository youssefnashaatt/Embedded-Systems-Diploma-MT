#include <stdio.h>


int check_even(int);

int main(void)
{
	int number;

	printf("Enter a number: ");
	fflush(stdout);
	scanf("%d", &number);

	if(check_even(number) == 0)
		printf("This number is even");

	else
		printf("This number is odd");

	return 0;

}


int check_even(int x)
{
	if ((x % 2) == 0)
		return 0;

	else
		return 1;
}
