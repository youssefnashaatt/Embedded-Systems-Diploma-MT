#include <stdio.h>
#include <math.h>

int main(void)
{
	float radius, circumference, area;
	printf("Please enter radius of the circle: \n");

	fflush(stdout);
	scanf("%f", &radius);

	circumference = 2 * M_PI * radius;
	area = M_PI * radius * radius;

	printf("The circumference of circle is %.2f", circumference);
	printf("\nThe area of circle is %.2f", area);


}
