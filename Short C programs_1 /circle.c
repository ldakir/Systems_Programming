// File: circle.c
// Purpose: prompts the user for a radius, then gives back the circumference
// and area of the circle. Repeats until 0 is entered.
// Written by: Lamiaa Dakir
// Date: 2/4/2019

#include <stdio.h>
#include <math.h>
int main(){
	int radius;
	float circumference;
	float area;
	while(1){
		// get radius of circle from user
		printf("Enter the radius of a circle: ");
		scanf("%d", &radius);
		if( radius == 0){
			break; //leave the loop if 0 is entered
		}

		else if (radius < 0){
			// return error message if the radius is negative and ask the user to try
			//again
			printf("Illegal radius: %d \nTry again.\n\n", radius);
			continue;
		}
		else{
			//compute the circumference and the area of the circle
			circumference = 2* M_PI * radius;
			area = M_PI * pow(radius,2);
			printf("The circumference of a circle with radius %d is %.3f \n", radius, circumference);
			printf("The area of a circle with radius %d is %.3e \n\n", radius, area);
		}
	} // end while
	printf("Good-bye.\n"); //Print Good-bye when the program finishes
	return 0;
}
