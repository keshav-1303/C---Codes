#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define ll long long int
#define print(arr, n)   {for(int i=0; i<n; i++)    printf("%d ",arr[i]);}   printf("\n");

int count(int *start, int *end, int value){
    int *i;   int count = 0;
    for(i = start; i <= end; i++){
        if(*i == value)    count++;
    }
    return count;
}

int main(){
	
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 6, 5, 3, 3, 3, 9, 0, 10 };
    int size = sizeof(arr)/sizeof(arr[0]);

    int freq = count(arr, arr + size, 3);

    printf("3 occurs %d times\n", freq);  

}