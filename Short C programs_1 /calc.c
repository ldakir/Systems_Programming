// File: calc.c
// Purpose: prompts the user for an operation and two numbers, then applies
// the operation to the number an gives back the results. Repeats until 0 is
// entered.
// Written by: Lamiaa Dakir
// Date: 2/4/2019

#include <stdio.h>

int main(){
	char op;
	int operand_1;
	int operand_2;
	int result;

	while(1){
		// get operation from user
		printf("Enter an operation: ");
		scanf(" %c", &op);
		if(op == '0'){
			break; //leave the loop if 0 is entered
		}
		// get operands from user
		printf("Enter a number: ");
		scanf("%d", &operand_1);
		printf("Enter a number: ");
		scanf("%d", &operand_2);

		switch(op){
			// Cases for different operations
			// Addition
			case '+': result = operand_1 + operand_2;
				  printf("%d + %d = %d \n", operand_1 , operand_2 ,result);
				  break;
			// Substruction
			case '-': result = operand_1 - operand_2;
				  printf("%d - %d = %d \n", operand_1 , operand_2 ,result);
				  break;
			// Multiplication
			case '*': result = operand_1 * operand_2;
				  printf("%d * %d = %d \n", operand_1 , operand_2 ,result);
				  break;
			// Division
			case '/':
				  switch(operand_2){
					  //handling division by 0
					  case 0: printf("Cannot divide by 0 \nTry again.\n\n");
						  break;
				  	  default:
						  result = operand_1 / operand_2;
				  		  printf("%d / %d = %d \n", operand_1 , operand_2 ,result);
				  	          break;

				} //end switch
				break;
			default:
					printf("Invalid Operator \nTry again.\n\n");
					continue;

		}// end switch

	} // end while
	printf("Good-bye.\n"); //Print Good-bye when the program finishes
	return 0;
}
