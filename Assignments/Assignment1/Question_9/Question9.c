#include <stdio.h>

int main(void)
{
	int grade;

	printf("Please enter your grade: ");
	fflush(stdout);
	scanf("%d", &grade);

	if (grade >= 85)
		printf("Excellent");

	else if ((grade < 85) && (grade >= 75))
		printf("Very good");

	else if ((grade < 75) && (grade >= 65))
		printf("Good");

	else
		printf("Fail");
}
