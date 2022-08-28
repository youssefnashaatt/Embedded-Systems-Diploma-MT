#include <stdio.h>

int main(void)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	float num1, num2;
	char operator;

	printf("Please enter num1:");
	scanf("%f", &num1);

	printf("Please enter num2:");
	scanf("%f", &num2);

	printf("Please choose operand (+, *, -, /):");
	fflush(stdout);
	scanf(" %c", &operator);

	switch (operator)
	{
		case '+':
			printf("The result is %.1f", num1 + num2);
			break;

		case '-':
			printf("The result is %.1f", num1 - num2);
			break;

		case '*':
			printf("The result is %.1f", num1 * num2);
			break;

		case '/':
			printf("The result is %.1f", num1 / num2);
			break;

	}

	return 0;
}
