#include <stdio.h>

int main(void)
{
	int Celsius, Farenheit;
	printf("Enter Temperature in Celsius: \n");

	//User Enter Temp in Celsius
	fflush(stdout);
	scanf("%d", &Celsius);

	//Converting to Farenheit
	Farenheit = Celsius * 9 / 5 + 32;

	//Printing in Farenheit
	printf("Temperature in Farenheit is %d", Farenheit);
}
