// File: array_pointers.c
// Purpose: Sort array and find minimum and maximum values and their positions using pointers
// Written by: Lamiaa Dakir
// Date: March 17, 2019

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 16

int randint(int a, int b);
void quicksort(int a[], int *low, int *high);
int *split(int a[], int *low, int *high);
void max_min(int a[], int n, int **max, int **min);

int main(void)
{
  srand(time(NULL));
  int max;
  int min;
  int *lowest;
  int *highest;
  int *p; //Pointer to traverse the array
  int values[N];
  int min_position;
  int max_position;


  //prompting user for a minimum value
  printf("What is the lowest value?\n");
  scanf("%d", &min);

  //prompting user for a maximum value
  printf("What is the highest value?\n");
  scanf("%d", &max);
  printf("\n");

  //filling an array of 16 ints with random values between the minimum and the maximum values using pointers
  for (p = values; p < values+N; p++) {
      *p = randint(min, max+1);
  }

  //printing the contents of the array using array_pointers
  printf("The random values generated are:\n");
  for (p = values; p < values+N; p++) {
      printf("%d ", *p);
  }
  printf("\n");

  //calling max_min and report the maximum and minimum values in the array and their location
  max_min(values, N, &highest, &lowest);

  int *start;
  start = &values[0]; //Pointer that points to the first element to be able to find positions

  min_position = lowest -start;//Computing location of the minimum position
  max_position = highest -start;//Computing location of the maximum position

  printf("\nThe minimum value is %d at position %d.\n", *lowest, min_position);
  printf("The maximum value is %d at position %d.\n", *highest,max_position);
  printf("\n");

  //sorting the array using qsort
  int *first= &values[0];
  int *last= &values[N-1];
  quicksort(values, first, last);
  //printing the sorted contents of the array using array_pointers
  printf("The sorted values are:\n");
  for (p = values; p < values+N; p++) {
      printf("%d ", *p);
  }
  printf("\n");

  //reporting the maximum and minimum values in the array and their location
  max_min(values, N, &highest, &lowest);
  min_position = lowest -start;
  max_position = highest -start;
  printf("\nThe minimum value is %d at position %d.\n", *lowest,min_position);
  printf("The maximum value is %d at position %d.\n", *highest,max_position);


}//main()

//Generating random numbers between a inclusive and b
int randint(int a, int b){
  return (int)(a+ rand()%(b-a));
}//randint()

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
}//max_min()

void quicksort(int a[], int *low, int *high){
  int *middle;
  if(low >= high) return;
  middle = split(a, low ,high);
  quicksort(a ,low, middle -1);
  quicksort(a, middle +1, high);
}//quicksort()

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
}//split()
