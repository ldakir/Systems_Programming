// File: sort.c
// Purpose: Tells you whether or not an array is sorted
// Written by: Lamiaa Dakir
// Date: 2/8/2019

#include<stdio.h>

//function that returns 1/0 depending on whether the array of ints is sorted
int sorted( int A[], int n){
  int result =1;
  while(n-1){
    if (A[n-1] > A[n-2]){
      n--; // if the order is correct continue looping
    }
    else{
      result = 0; // if the order is not correct set the result to be 0
      break;
    }
  } // end while
  return result;
} // end sorted

int main(){
  int x[10]; // initialize the array of length 10
  for (int i = 0; i < 10; i++){
    x[i] = i ; // initialize the elements of the array
  }

  //x[5] = -9;

  int result = sorted(x,10);

  for (int i = 0; i < 10; i++){
    printf("%d\n",x[i]); // Printing the elements of the array
  }

  //Printing if the array is sorted or unsorted
  switch(result){
    case 0: printf("Unsorted\n");
              break;
    case 1: printf("Sorted\n");
              break;
  }
  return 0;

}
