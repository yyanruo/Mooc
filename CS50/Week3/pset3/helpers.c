/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    for(int i = 0 ; i < n ; i++){
        if(value==values[i]){
            return true;
        }
    }
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int value[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    
    //bubble sort
   int k =1;
   int tmp = 0;
   while(k!=0){
       k = 0;
       for(int i = 0 ;i<n;i++){
           if(value[i]>value[i+1]&&value[i+1]!=NULL){
               tmp = value[i];
               value[i] = value[i+1];
               value[i+1] = tmp;
               k++;
           }
       }
   } 
    return;
}