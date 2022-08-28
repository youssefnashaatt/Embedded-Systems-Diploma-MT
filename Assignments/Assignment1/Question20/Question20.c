#include <stdio.h>

int main(void)
{
	int height, width;

	printf("Please enter the height of the pyramid: ");
	fflush(stdout);
	scanf("%d", &height);

	width = (height * 2) + 1;

	for (int i = 0 ; i < height ; i++)
	{
		for (int j = 1 ; j < (width / 2) - i ; j++)
		{
			printf(" ");
		}

		for (int k = 0 ; k < (i * 2) + 1 ; k++)
		{
			printf("*");
		}

		for (int j = 1 ; j < (width / 2) - i ; j++)
		{
			printf(" ");
		}

		printf("\n");

	}

	return 0;
}


