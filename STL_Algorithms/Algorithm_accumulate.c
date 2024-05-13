#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int accumulate(int *start, int *end, int base){
    int sum = base;
    int *i;
    for(i = start; i < end; i++){
        sum += *i;
        // printf("Sum is now : %d\n",sum);
    }
    return sum;
}

int main(){
	
    int arr[] = { 8, 11, 5, 7, 2, 3, 4, 5 };    int n = sizeof(arr)/sizeof(arr[0]);

    int sum = accumulate(arr, arr + n, 0);

    printf("%d\n", sum);

	return 0;
}