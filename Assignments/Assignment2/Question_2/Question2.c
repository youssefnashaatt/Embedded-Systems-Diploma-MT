#include <stdio.h>


//Function Declaration
int bool_check_alphabetic (char c);

int main(void)
{
	char character;

	printf("Please enter a character: ");
	fflush(stdout);
	scanf(" %c", &character);

	switch (bool_check_alphabetic(character))
	{
		case 1:
			printf("You have entered an alphabetic character");
			break;

		case 0:
			printf("You haven't entered an alphabetic character");
			break;

		default:
			printf("You haven't entered a character");
	}

	return 0;
}



int bool_check_alphabetic (char c)
{
	if ((c >= 65) && (c <= 90))
		return 1;

	else if ((c >= 97) && (c <= 122))
		return 1;

	else
		return 0;
}
