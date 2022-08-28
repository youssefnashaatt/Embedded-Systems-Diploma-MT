/**************************************************************************************************
 Name        : Question13.c
 Author      : Youssef Nashaat
 Created on	 : Aug 19, 2022
 Description : Assignment 2 - Question 13
 **************************************************************************************************/
#include <stdio.h>


int floor_float(float num1, float num2)
{
	return (int)(num1 + num2);
}


int main(void)
{
	printf("Integer add of 2.5 and 3.2 is %d\n", floor_float(2.5,3.2));
	printf("Integer add of 7.8 and 4.5 is %d\n", floor_float(7.8,4.5));

	return 0;
}


