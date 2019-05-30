// File: assignment9.c
// Purpose: Search for a zipcode in a linked list and return the city, state, latitude and longitude
// Written by: Lamiaa Dakir
// Date: April 24, 2019

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE 100

struct Zipnode{
  char zipcode[6];
  char *city;
  char state[3];
  float latitude;
  float longitude;
  struct Zipnode *next;
}; //Zipnode struct

struct Zipnode *search_list(struct Zipnode *list, char *zip);

int main(){
  FILE *zipcodeCSV = fopen("zipcodeCSV.csv", "r"); //opening the file
  int num_elements =0; //number of elements in the file
  char line[MAX_LINE];

  struct Zipnode *first = NULL; //initializing the linked list
  struct Zipnode *new_node;
  char *tempstring;

  if(zipcodeCSV == NULL){
    printf("Error! Could not open file.\n");
    return -1;
  } //bad open

  while (NULL != fgets(line,MAX_LINE,zipcodeCSV)) { // input next line until reach null

    num_elements++; // increment number of elements
    new_node = malloc(sizeof(struct Zipnode)); //allocate amount of memory needed

    strcpy(new_node->zipcode, strtok(line,",")); //zipcode

    tempstring = strtok(NULL,",");
    new_node->city = malloc(strlen(tempstring)+1);
    strcpy(new_node->city,tempstring); //city

    strcpy(new_node->state, strtok(NULL,",")); //state

    new_node->latitude = atof(strtok(NULL,",")); //latitude

    new_node->longitude = atof(strtok(NULL,",")); //longitude

    //link node the linked list
    new_node->next = first;
    first = new_node;
  }

  char input[6];
  printf("Found %d zip codes.\n\n",num_elements); //number of zipcodes in the file
  printf("Enter a zip code (type STOP to end): "); // prompt user for a zipcode
  gets(input);
  while(strcmp(input,"STOP") != 0){

    //Search for the zipcode in the linked list
    struct Zipnode *result =search_list(first,input);
    if(result != NULL)
      //print the result
      printf("%s, %s latitude %.2f longitude %.2f\n\n", result->city, result->state, result->latitude,result->longitude);
    else
      printf("Not found.\n\n"); //the zipcode doesn't exist

    printf("Enter another zip code (type STOP to end): "); // prompt user for another zipcode
    gets(input);
  }

  printf("Goodbye!\n");

  //freeing all malloc'd memory
  struct Zipnode *p;
  for (p = first; p != NULL; p = p->next){
      free(p->city);//freeing the malloc'd memory inside the node
      free(p); //freeing the node
  }
  return 0;
}

//function that search for a zipcode in the linked list
//it returns the zipnode if it find the zipcode or null if it doesn't exist
struct Zipnode *search_list(struct Zipnode *list, char *n){
  struct Zipnode *p;
  for (p = list; p != NULL; p = p->next)
      if (strcmp(p->zipcode, n) == 0)
        return p;
  return NULL;
}
