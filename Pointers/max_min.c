// File: max_min.c
// Purpose: Modifying the max_min function so that it uses a pointer
// Written by: Lamiaa Dakir
// Date: March 17, 2019

#include <stdio.h>
#define N 10

void max_min(int a[], int n, int **max, int **min);

int main(void)
{
  int b[N], i , *big, *small;
  printf("Enter %d numbers: ", N);
  for( i =0; i < N; i++)
    scanf("%d", &b[i]); //Prompting user for numbers to sort

  max_min(b, N, &big, &small); //Calling ther max_min function
  
  printf("Largest: %d\n", *big); //Returning the value of the maximum value
  printf("Smallest: %d\n", *small); //Returning the value of the minimum value
  return 0;
}//main()


void max_min(int a[], int n, int **max, int **min)
{
  int *i;
  *max = *min = &a[0];
  for(i = a; i < a+n; i++){
    if(*i > **max){
      *max = i;
    }
    else if (*i < **min){
      *min = i;
    }
  }
} //max_min()
