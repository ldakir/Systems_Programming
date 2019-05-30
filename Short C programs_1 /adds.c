// File: adds.c
// Purpose: prompts the user for numbers and gives back their sum
// Written by: Lamiaa Dakir
// Date: 2/4/2019

#include <stdio.h>

int main(){
	int result = 0;
	int input;
	while(input!=0){
		// get numbers from user
		printf("Enter a number: ");
		scanf("%d", &input);
		// add up the numbers
		result += input;
	} // end while
	printf("Sum:%d\n ", result);
	return 0;
}
