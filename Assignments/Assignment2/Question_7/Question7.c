#include <stdio.h>

int bool_ismultiple (int, int);

int main(void)
{
	int num1, num2;

	printf("Please enter 2 integers:\n");
	fflush(stdout);
	scanf("%d", &num1);
	scanf("%d", &num2);

	if(bool_ismultiple(num1, num2) == 1)
		printf("First number is multiple of second");

	else
		printf("First number isn't multiple of second");


	return 0;

}


int bool_ismultiple (int n1, int n2)
{
	if ((n1 % n2) == 0)
		return 1;

	else
		return 0;
}
