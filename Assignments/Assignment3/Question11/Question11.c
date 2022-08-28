/**************************************************************************************************
 Name        : Question11.c
 Author      : Youssef Nashaat
 Created on	 : Aug 23, 2022
 Description : Assignment 3 - Question 11
 **************************************************************************************************/
#include <stdio.h>
#include <string.h>

int count_character(char s[],char character)
{
	int i,frequency = 0;
	for(i = 0; s[i] != '\0'; i++) /* loop untill the end of the string */
    {
		if(character == s[i])
		{
			/* increment the frequency in match case */
			++frequency;
		}
    }
	return frequency;
}

int main()
{
   char str[1000];
   char ch;
   int count;

   printf("Enter a string: ");
   gets(str);

   printf("Enter a character to find the frequency: ");
   scanf("%c",&ch);

   count = count_character(str,ch);

   printf("Frequency of %c = %d", ch, count);

   return 0;
}
