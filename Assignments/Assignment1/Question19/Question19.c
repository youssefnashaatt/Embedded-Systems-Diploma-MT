#include <stdio.h>

int main(void)
{
	int height;

	printf("Please enter the height of the pyramid: ");
	fflush(stdout);
	scanf("%d", &height);


	for (int i = 0 ; i < height ; i++)
	{
		for (int j = i ; j < height ; j++)
		{
			printf("*");
		}

		printf("\n");
	}

	return 0;
}
