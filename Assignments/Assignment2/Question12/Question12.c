/**************************************************************************************************
 Name        : Question12.c
 Author      : Youssef Nashaat
 Created on	 : Aug 19, 2022
 Description : Assignment 2 - Question 12
 **************************************************************************************************/
#include <stdio.h>

int calc_heating_time(int temp);


int main(void)
{
	int temp;

	printf("Please enter temperature of water:\n");
	fflush(stdout);
	scanf("%d", &temp);

	printf("Heating time required is %d mins", calc_heating_time(temp));

	return 0;
}


int calc_heating_time(int temp)
{
	if(temp > 0 && temp <= 30)
		return 7;

	else if(temp > 30 && temp <= 60)
		return 5;

	else if(temp > 60 && temp <= 90)
		return 3;

	else if(temp > 90 && temp <= 100)
		return 1;

	else
		return 0;

}

