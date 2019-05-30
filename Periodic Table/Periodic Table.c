// File: assignment8.c
// Purpose: Allow the user to search for an element using either the atomic number,the name,or the chemical symbol
// Written by: Lamiaa Dakir
// Date: April 13, 2019

#include <stdio.h>
#include <string.h>
#include <math.h>

//Defining a structure type element_t
typedef struct{
  int atomic_number;
  char name[20];
  char chemical_symbol[5];
  char class [20];
  double atomic_weight;
  int electrons[7];
}element_t;

//Defining 6 different elements and storing them in the elems array
element_t elems[] ={
  { 1, "Hydrogen", "H", "non_metal", 1.0079, {1,0,0,0,0,0,0}},
  { 20, "Calcium", "Ca", "alkaline_earth_metal", 40.078, {2,8,8,2,0,0,0}},
  { 26, "Iron", "Fe", "transition_metal", 55.845, {2,8,1,4,2,0,0}},
  { 82, "Lead", "Pb", "poor_metal", 207.2 , {2,8,18,32,18,4,0}},
  { 17, "Chlorine", "Cl", "halogen", 35.453, {2,8,7,0,0,0,0}},
  { 10, "Neon", "Ne", "noble_gas", 55.845, {2,8,0,0,0,0,0}}
};

void print_element(element_t e);
int tonum(char * str);

int main(){
  char input[10];
  printf("Enter Atomic Number, Name or Chemical Symbol:\n");
  gets(input); // prompt user for Atomic Number, Name or Chemical Symbol

  //check if the input is an element inthe array
  for(int i=0; i<6; i++){
    if(strcmp(elems[i].name,input) ==0){
      print_element(elems[i]);
    }
    else if(strcmp(elems[i].chemical_symbol,input) ==0){
      print_element(elems[i]);
    }
    else if(elems[i].atomic_number == tonum(input)){
      print_element(elems[i]);
    }
    else{
      continue;
    }
  }
}//main()

//Function that prints out the details of an individual element
void print_element(element_t e)
{
  printf("%d %s %s %s %f ", e.atomic_number, e.name, e.chemical_symbol, e.class, e.atomic_weight);
  for(int i =0; i < 7; i++)
    printf("%d ", e.electrons[i]);

  printf("\n");
}//print()

//Function that converts string to a number
int tonum(char * str){
  int result =0;
  int l = strlen(str)-1;
  for(int i =0; i<strlen(str); i++){
    result += pow(10,i)*(str[l]-'0');
    l--;
  }
  return result;
}//tonum()
