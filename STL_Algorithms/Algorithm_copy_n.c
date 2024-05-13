#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define ll long long int
#define print(arr, n)   {for(int i=0; i<n; i++)    printf("%d ",arr[i]);}   printf("\n");

void copy_n(int *start, int n, int *copy_to){
    int *i;    int count = 0;
    while (count < n){
        *copy_to++ = *start++;
        count++;
    }
}

int main(){
	
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 6, 5, 3, 3, 3, 9, 0, 10};
    int size = sizeof(arr)/sizeof(arr[0]); 

    int arr1[size];

    copy_n(arr, size, arr1);

    print(arr1, size); 

	return 0;
}