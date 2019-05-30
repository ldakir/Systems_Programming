// File: shout.c
// Purpose: Takes whatever the user types on the keyboard and print it back out, all
//in uppercase letters
// Written by: Lamiaa Dakir
// Date: 2/8/2019

#include<stdio.h>
#include <ctype.h>

int main(){
  char c;
  while((c = getchar()) != EOF){ //keep looping until the end of file
    putchar(toupper(c)); // Capitalize the characters and print them out
  } //end while
  return 0;
}
