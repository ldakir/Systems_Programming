// File: songsdb.c
// Purpose: Search for song information in the musicsampleCSV file using linked lists
// Written by: Lamiaa Dakir
// Date: April 27, 2019

#include <stdio.h>
#include "search.h"

int main(){
  FILE *musicsampleCSV = fopen("musicsampleCSV.csv", "r"); //opening the file
  char line[MAX_LINE];

  struct musicnode *first = NULL; //initializing the linked list
  struct musicnode *new_node;
  char *tempstring;
  int num_records=0;

  if(musicsampleCSV == NULL){
    printf("Error! Could not open file.\n");
    return -1;
  } //bad open

  while (NULL != fgets(line,MAX_LINE,musicsampleCSV)) { // input next line until reach null
    num_records++;
    new_node = malloc(sizeof(struct musicnode)); //allocate amount of memory needed

    tempstring = strtok(line,",");
    new_node->title = malloc(strlen(tempstring)+1);
    strcpy(new_node->title,tempstring); //title

    tempstring = strtok(NULL,",");
    new_node->artist = malloc(strlen(tempstring)+1);
    strcpy(new_node->artist,tempstring); //artist

    new_node->duration = atof(strtok(NULL,",")); //duration

    tempstring = strtok(NULL,",");
    new_node->release = malloc(strlen(tempstring)+1);
    strcpy(new_node->release,tempstring); //release

    new_node->start_of_fade_out = atof(strtok(NULL,","));//start_of_fade_out
    new_node->tempo = atof(strtok(NULL,","));//tempo

    tempstring = strtok(NULL,",");
    new_node->terms = malloc(strlen(tempstring)+1);
    strcpy(new_node->terms,tempstring);//terms

    new_node->year = atoi(strtok(NULL,",")); //year

    //link node the linked list
    new_node->next = first;
    first = new_node;
  }
  printf("Read %d songs\n", num_records);
  printf("Longest song: %f seconds\n",max_duration(first));
  printf("Shortest song: %f seconds\n",min_duration(first));
  printf("Average song length: %f seconds\n",average(first,num_records));
  printf("Oldest song in list was recorded in %d\n", oldest(first));
  printf("Newest song in list was recorded in %d\n\n", newest(first));

  int choice;
  char input[20];
  printf("Enter 1 to search on year, 2 to search on duration, 3 to search on artist, 4 to search on genre, 0 to stop.\n");
  scanf("%d",&choice);
  while(choice !=0){
    if(choice == 1){
      int min_year;
      int max_year;
      printf("You chose to search on year.\n"); //searching for a year
      printf("The dates range from year %d to %d.\n\n",oldest(first),newest(first));
      printf("Enter the earliest year you want to search: "); //prompt the user for a year
      scanf("%d",&min_year);

      printf("Enter the latest year you want to search: "); //prompt the user for a year
      scanf("%d",&max_year);

      printf("\nYou chose the range %d-%d\n", min_year, max_year);
      if(min_year > max_year){
        printf("Sorry, that range is invalid.\n"); //The range is not valid
      }
      else{
        search_year_range(first, min_year, max_year); //call a search function to search in the linked list for dates in the range
      }

      printf("\n\n");
      printf("Enter 1 to search on year, 2 to search on duration, 3 to search on artist, 4 to search on genre, 0 to stop.\n");
      scanf("%d",&choice);

    }//search for year

    else if(choice == 2){
      float min;
      float max;
      printf("You chose to search on duration.\n"); //searching for a duration
      printf("Duration of songs range from %f seconds to %f seconds.\n",min_duration(first),max_duration(first));
      printf("Enter the shortest duration to select (in seconds): "); //prompt the user for a year
      scanf("%f",&min);

      printf("Enter the longest duration to select (in seconds): "); //prompt the user for a year
      scanf("%f",&max);

      printf("You chose the range %f-%f.\n", min, max);
      if(min > max){
        printf("Sorry, that range is invalid.\n"); //The range is not valid
      }
      else{
        search_duration_range(first, min, max); //call a search function to search in the linked list for durations in the range
      }
      printf("\n\n");
      printf("Enter 1 to search on year, 2 to search on duration, 3 to search on artist, 4 to search on genre, 0 to stop.\n");
      scanf("%d",&choice);

    }//search for duration

    else if(choice == 3){
      printf("You chose to search on artist.\n"); //searching for an artist
      printf("Enter a search term for the artist field: "); //prompt the user for a genre
      scanf(" %[^\n]s",input);
      printf("\nYou are searching for %s.\n", input);
      search_artist(first,input); //call a search function to search for the genre in the linked list

      printf("\n\n");
      printf("Enter 1 to search on year, 2 to search on duration, 3 to search on artist, 4 to search on genre, 0 to stop.\n");
      scanf("%d",&choice);

    }//search for artist

    else if(choice == 4){
      printf("You chose to search on genre.\n"); //searching for a genre
      printf("Enter a search term for the genre field: "); //prompt the user for a genre
      scanf(" %[^\n]s",input);
      printf("You are searching for %s.\n", input);
      search_terms(first,input); //call a search function to search for the genre in the linked list

      printf("\n\n");
      printf("Enter 1 to search on year, 2 to search on duration, 3 to search on artist, 4 to search on genre, 0 to stop.\n");
      scanf("%d",&choice);

    }//search for genre
    else{
      printf("Invalid entry, try again.\n");
      printf("\n\n");
      printf("Enter 1 to search on year, 2 to search on duration, 3 to search on artist, 4 to search on genre, 0 to stop.\n");
      scanf("%d",&choice);
    }

  }
    printf("\n\n");
    printf("Goodbye!\n");


    //freeing all malloc'd memory
    struct musicnode *p;
    for (p = first; p != NULL; p = p->next){
        //freeing the malloc'd memory inside the node
        free(p->title);
        free(p->artist);
        free(p->release);
        free(p->terms);

        //freeing the node
        free(p);
    }
    return 0;
}
