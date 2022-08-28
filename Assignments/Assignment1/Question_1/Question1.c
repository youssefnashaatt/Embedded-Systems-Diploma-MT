#include <stdio.h>

int main(void)
{
	int num1, num2, result;
	printf("Please enter 2 numbers:\n");
	fflush(stdout);
	scanf("%d %d", &num1, &num2);

	result = ((num1 - num2) * 3) - 10;
	printf("\n The result is %d", result);
}
