#include <stdio.h>

int main(void)
{
	int numbers[3];
	int MIN;

	printf("Please enter 3 Numbers: ");
	fflush(stdout);

	scanf("%d", &numbers[0]);
	scanf("%d", &numbers[1]);
	scanf("%d", &numbers[2]);


	MIN = numbers[0];

	for (int i = 1 ; i < 3 ; i++)
	{
		if (numbers[i] < MIN)
		{
			MIN = numbers[i];
		}
	}

	printf("The minimum number is %d", MIN);
	return 0;
}
