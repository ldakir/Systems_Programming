// File: digital_display.c
// Purpose:  Display input number using characters
// to simulate the effect of a seven-segment LCD array
// Written by: Lamiaa Dakir
// Date: Feb 28, 2019

#include<stdio.h>
#include<ctype.h>


#define MAX_DIGITS 10 //Maximum digits allowed

char digits[3][MAX_DIGITS*4]; //digits array that stores the seven-segment representation of the digits


//Segment array that stores data representing the correspondence between digits and segments
const int segments[10][7] = {{1,1,1,1,1,1,0}, //0
                                     {0,1,1,0,0,0,0}, //1
                                     {1,1,0,1,1,0,1}, //2
                                     {1,1,1,1,0,0,1}, //3
                                     {0,1,1,0,0,1,1}, //4
                                     {1,0,1,1,0,1,1}, //5
                                     {1,0,1,1,1,1,1}, //6
                                     {1,1,1,0,0,0,0}, //7
                                     {1,1,1,1,1,1,1}, //8
                                     {1,1,1,0,0,1,1}}; //9

void clear_digits_array(void); //store blank characters into all elements of the digits array
void process_digit(int digit, int position); //will store the seven-segment representation of digit into
//specified position in the digits array (position range from 0 to MAX_DIGITS -1)
void print_digits_array(void); // will display the rows of the digits array each on a single line

void clear_digits_array(void){
  for(int i=0; i<3; i++){
    for(int  j = 0;j < MAX_DIGITS*4; j++){
      digits[i][j] = ' '; //storing blank characters
    }
  }
}//clear_digits_array()

void process_digit(int digit, int position){
  // Storing the seven-segment representation of digit in the array digits
  for(int i =0; i <7; i++){
    if (segments[digit][i] ==1){
      if(i == 0){
        digits[0][position+1]= '_';
      }
      else if(i == 6){
        digits[1][position+1]= '_';
      }
      else if(i == 3){
        digits[2][position+1]= '_';
      }
      else if(i ==5){
        digits[1][position]= '|';
      }
      else if(i ==4){
        digits[2][position]= '|';
      }
      else if(i ==1){
        digits[1][position+2]= '|';
      }
      else if(i ==2){
        digits[2][position+2]= '|';
      }
    }
  }
} //process_digit()

void print_digits_array(void){
  for(int i=0; i<3; i++){
    for(int  j = 0;j < MAX_DIGITS*4; j++){
      printf("%c", digits[i][j]); //Printing digit array to display the seven segment representation of a number
    }
      printf("\n");// new line after each row
  }
} //print_digits_array()



int main(){
  printf("program will transform the numerals into a 7-segment display. To stop looping, type the enter key with no input.\n\n");
  char input[50];
  //prompt user for a number
  printf("Enter number: ");
  fgets(input, sizeof input, stdin); //scanf ignores new line so I had to use fgets. Source: https://stackoverflow.com/questions/30220691/how-to-get-empty-input-or-only-enter-in-c
  while(input[0] != '\n'){
    //Store blank characters into digits
    clear_digits_array();
    int max = 0;
    int c =0;

    //Check if the character is a digit and process it
    while(input[c]!= '\0'){ //How to detect end of string: https://www.programiz.com/c-programming/examples/string-length
      if(isdigit(input[c]) && max != MAX_DIGITS){
        int num = input[c] -'0'; // How to convert from char digit to int: https://stackoverflow.com/questions/628761/convert-a-character-digit-to-the-corresponding-integer-in-c
        process_digit(num, max*4); //process one digit at a time
        max++; //count how many digits have been processed
      }
      else if(max == MAX_DIGITS ){
        break; //if MAX_DIGITS digits was reached, break from the loop
      }
      c++;
      //print_digits_array();


    }//end while

    //Display the number
    print_digits_array();

    printf("\nEnter number: ");

    fgets(input, sizeof input, stdin);
  }//end while
  printf("\nThank you and goodbye!\n");

  return 0;

}// int main()
