#include <stdio.h>

//Function Declaration
float operate (float, float, char);


int main(void)
{
	float num1, num2;
	char operator;

	printf("Please Enter 2 numbers.\nNum1: ");
	fflush(stdout);
	scanf("%f", &num1);
	printf("num2: ");
	fflush(stdout);
	scanf("%f", &num2);

	printf("Please enter an operation (+, -, /, *):\n");
	fflush(stdout);
	scanf(" %c", &operator);

	float result = operate(num1, num2, operator);

	printf("%.0f %c %.0f = %0.f", num1, operator, num2, result);

	return 0;
}



float operate (float num1, float num2, char operator)
{

	switch (operator)
	{
	case '+':
		return num1 + num2;
		break;

	case '-':
		return num1 - num2;
		break;

	case '*':
		return num1 * num2;
		break;

	case '/':
		return num1 / num2;
		break;

	default:
		printf("You have entered a wrong operator.");
		return 0;

	}
}
