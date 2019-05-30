// File: music.c
// Purpose:
// Written by: Lamiaa Dakir
// Date: April 27, 2019

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "songsdb.h"
#include "search.h"
#define MAX_LINE 100
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)>(y)?(y):(x))
#define AVERAGE(max,min,total) ((max+min)/total)

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

int main(){
  FILE *musicsampleCSV = fopen("musicsampleCSV.csv", "r"); //opening the file
  list = database(musicsampleCSV);



}
