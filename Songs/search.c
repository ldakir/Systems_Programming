// File: search.c
// Purpose: define functions to search and report information about the collection
// Written by: Lamiaa Dakir
// Date: April 29, 2019

#include "search.h"


void search_year_range(struct musicnode *list, int min_range,int max_range){
  struct musicnode *p;
  int found=0;
  for (p = list; p != NULL; p = p->next)
      if (p->year<= max_range & p->year>= min_range){
        printf("%s,%s,%f,%s,%f,%f,%s,%d\n", p->title, p->artist, p-> duration, p->release, p->start_of_fade_out, p->tempo, p->terms, p->year);
        found +=1;
      }
  if(found==0){
    printf("Sorry, no songs found that meet those criteria.\n");
  }
}//year_range()

void search_duration_range(struct musicnode *list, float min_range,float max_range){
  struct musicnode *p;
  int found =0;
  for (p = list; p != NULL; p = p->next)
      if (p->duration<= max_range & p->duration>= min_range){
        printf("%s,%s,%f,%s,%f,%f,%s,%d\n", p->title, p->artist, p-> duration, p->release, p->start_of_fade_out, p->tempo, p->terms, p->year);
        found +=1;
      }
  if(found==0){
    printf("Sorry, no songs found that meet those criteria.\n");
  }
}//duration_range()

void search_artist(struct musicnode *list, char *name){
  struct musicnode *p;
  int found =0;
  for (p = list; p != NULL; p = p->next)
      if (strstr(p->artist, name) != NULL){
        printf("%s,%s,%f,%s,%f,%f,%s,%d\n", p->title, p->artist, p-> duration, p->release, p->start_of_fade_out, p->tempo, p->terms, p->year);
        found +=1;
      }
  if(found==0){
    printf("Sorry, no songs found that meet those criteria.\n");
  }
}//artist()

void search_terms(struct musicnode *list, char *title){
  struct musicnode *p;
  int found =0;
  for (p = list; p != NULL; p = p->next)
      if (strstr(p->terms, title) != NULL){
        printf("%s,%s,%f,%s,%f,%f,%s,%d\n", p->title, p->artist, p-> duration, p->release, p->start_of_fade_out, p->tempo, p->terms, p->year);
        found += 1;
      }
  if(found==0){
    printf("Sorry, no songs found that meet those criteria.\n");
  }

}//search_title()

float max_duration(struct musicnode *list){
  struct musicnode *p;
  p = list;
  float max= p->duration;
  p = p->next;
  for (; p != NULL; p = p->next){
      max= MAX(p->duration,max);
  }
  return max;
}//max_duration()

float min_duration(struct musicnode *list){
  struct musicnode *p;
  p = list;
  float min= p->duration;
  p = p->next;
  for (; p != NULL; p = p->next){
      min= MIN(p->duration,min);
  }
  return min;
}//min_duration()

float average(struct musicnode *list, int num){
  struct musicnode *p;
  float total_duration=0;
  for (p = list; p != NULL; p = p->next){
    total_duration += p->duration;
  }
  float average = total_duration/num;
  return average;
}//average()

int oldest(struct musicnode *list){
  struct musicnode *p;
  p = list;
  int oldest_song= p->year;
  p = p->next;
  for (; p != NULL; p = p->next){
      oldest_song= MIN(p->year,oldest_song);
  }
  return oldest_song;
}//oldest()

int newest(struct musicnode *list){
  struct musicnode *p;
  p = list;
  int newest_song= p->year;
  p = p->next;
  for (; p != NULL; p = p->next){
      newest_song= MAX(p->year,newest_song);
  }
  return newest_song;
}//newest()
