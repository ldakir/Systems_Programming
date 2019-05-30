// File: search.h
// Purpose: defining headers
// Written by: Lamiaa Dakir
// Date: April 29, 2019

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE 500
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)>(y)?(y):(x))


struct musicnode{
  char *title;
  char *artist;
  float duration;
  char *release;
  float start_of_fade_out;
  float tempo;
  char *terms;
  int year;
  struct musicnode *next;
}; //musicnode struct

void search_year_range(struct musicnode *list, int min_range,int max_range);
void search_duration_range(struct musicnode *list, float min_range,float max_range);
void search_artist(struct musicnode *list, char *name);
void search_terms(struct musicnode *list, char *title);
float max_duration(struct musicnode *list);
float min_duration(struct musicnode *list);
float average(struct musicnode *list, int num);
int oldest();
int newest();
