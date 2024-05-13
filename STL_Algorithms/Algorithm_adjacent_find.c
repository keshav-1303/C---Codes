#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int *adjacent_find(int *start, int *end){

    int *i;
    for(i = start; i <= end; i++){
        if( *i == *(i+1) )    return i;
    }
}

int main(){
    
    int arr[] = { 10, 13, 16, 16, 18, 18 };  // Sorted Array is must!!!
 
    int n = sizeof(arr) / sizeof(arr[0]);
 
    int *it;
    
    it = adjacent_find(arr, arr + n);   //returns address of 1st reapeating element.

    // Printing the result
    printf("Index : %d\n", it - arr);     //Getting index
    printf("Value : %d", *it);    //Getting value
}