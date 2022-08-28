#include <stdio.h>


int main(void)
{
	char c;
	printf("Please enter a character: ");
	fflush(stdout);
	scanf("%c", &c);
	printf("%d", c);
}
