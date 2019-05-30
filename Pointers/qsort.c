// File: qsort.c
// Purpose: Using pointers to array elements rather than integers
// Written by: Lamiaa Dakir
// Date: March 17, 2019

#include <stdio.h>

#define N 10

// From C Programming K. N. KING
void quicksort(int a[], int *low, int *high);
int *split(int a[], int *low, int *high);

int main(void){
  int a[N], i;
  int *low= &a[0]; //pointer for low
  int *high= &a[N-1]; //pointer for high

  printf("Enter %d numbers to be sorted: ", N );
  for (i = 0; i < N; i++)
    scanf("%d", &a[i]); //Prompting user for numbers to sort

  quicksort(a,low, high); //Sorting numbers using quicksort

  printf("In sorted order: ");
  for(i = 0; i < N; i++)
    printf("%d ", a[i]); //Printing sorted numbers
  printf("\n");

  return 0;

}//main()

void quicksort(int a[], int *low, int *high){
  int *middle; //pointer for middle
  if(low >= high) return;
  middle = split(a, low ,high);
  quicksort(a ,low, middle -1);
  quicksort(a, middle +1, high);
} //quicksort()

int *split(int a[], int *low, int *high){
  int part_element = *low;
  for(;;){
    while(low < high && part_element <= *high)
      high--;
    if (low >= high) break;
    *low++ = *high;
    while(low < high && *low <= part_element)
      low++;
    if(low >= high) break;
    *high-- = *low;
  }
  *high = part_element;
  return high;
} //split()
