#include <stdio.h>

/*Functions declarations*/
int power(int, int);

int main(void){

	int number;
	int power_value;
	int result;

	printf("Please enter a number: ");
	fflush(stdout);
	scanf("%d", &number);

	printf("Please enter the power value: ");
	fflush(stdout);
	scanf("%d", &power_value);

	result = power(number, power_value);

	printf("The result of %d^%d = %d", number, power_value, result);
}


int power(int number, int power_value)
{
	int result = 1;

	for (int i = 0 ; i < power_value ; i++)
	{
		result *= number;
	}

	return result;
}
