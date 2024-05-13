//Print first and last occurence of an element in a sorted array using binary search

#include <stdio.h>
#include <stdlib.h>

void bin(int *arr, int n, int key){

    int start = 0, end = n-1;
    int mid = start + (end-start)/2;
    int ans = -1, ans2 = -1;

    while(start <= end){
        if(arr[mid] == key){
            int i = mid, j = mid;

            while(arr[i] == arr[i-1])     i--;
            ans = i+1;

            while(arr[j] == arr[j+1])     j++;
            ans2 = j+1;
        }

        if(arr[mid]>key)    start=mid+1;
        else    end=mid-1;
        
        mid=start+(end-start)/2;
    }
    printf("START  : %d\n",ans);
    printf("END  : %d\n",ans2);
}

int main(){
	
    // int n;   printf("Enter n : ");    scanf("%d",&n);
    // int *arr;
    // arr=(int*)malloc(n*sizeof(int));

    // for(int i=0; i<n; i++){
    //     printf("Enter element %d : ",i+1);
    //     scanf("%d",&arr[i]);
    // }

    int arr[10] = {1,3,4,4,4,4,5,6,7,8};

    int n = 10;

    int key;   printf("Enter key : ");    scanf("%d",&key);

    bin(arr, n, key);
	
	return 0;
}