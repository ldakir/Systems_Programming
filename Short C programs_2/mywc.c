// File: mywc.c
// Purpose: Reports how many lines, words and characters have been read
// Written by: Lamiaa Dakir
// Date: 2/8/2019

#include<stdio.h>
#include <ctype.h>
int main(){
  int line = 0; // initial number of lines
  int word = 0; // initial number of words
  int character = 0;// initial number of characters
  char c;

  while((c = getchar()) != EOF){ // keep looping until end of file
    character ++; // increment number of characters
    // Case when c is a space
    if(isspace(c)){
      word ++; // increment number of words
    }
    // Case when c is a newline
    if(c == '\n'){
      line ++; // increment number of lines
    }

  } //end while
  printf("%d %d %d\n", line, word, character); // Print the result

}
