#include <stdio.h>


void uppercasing(char *c);

int main(void)
{
	char s[30];

	printf("Please enter a string: ");
	fflush(stdout);
	gets(s);

	uppercasing(s);

	printf("%s", s);

}

void uppercasing(char *c)
{
	while (*c != '\0')
	{
		if((*c >= 97) && (*c <= 122))
			*c -= 32;

		c++;
	}
}
