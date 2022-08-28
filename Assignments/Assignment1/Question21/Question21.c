#include <stdio.h>

int main(void)
{
	int height;

	printf("Please enter the height of the pyramid: ");
	fflush(stdout);
	scanf("%d", &height);

	for (int i = 0 ; i <= height ; i++)
	{
		for (int j = 0 ; j <= height ; j++)
		{
			if (j == i)
				printf("*");

			else if (j == height - i)
				printf("*");

			else
				printf(" ");
		}

		printf("\n");
	}
}
