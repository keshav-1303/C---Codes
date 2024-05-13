/* Given an unsorted array of integers, sort the array into a wave array. An array arr[0..n-1] is sorted in  wave form if:
 arr[0] >= arr[1] <= arr[2] >= arr[3] <= arr[4] >= …..                                                  */

#include <bits/stdc++.h>
using namespace std;

void print(int *arr, int n){
    for(int i=0; i<n; i++)    cout << arr[i] << " ";
    cout << endl;
}

void wave(int *arr, int n){

    for(int i=0; i<n-1; i++){
        if(i%2==0){
            if(arr[i+1]>arr[i])    swap(arr[i], arr[i+1]);
        }

        else{
            if(arr[i]>arr[i+1])    swap(arr[i], arr[i+1]);
        }
    }
}

void Wave(int *arr, int n){

    sort(arr, arr+n, greater<int>());

    for(int i=1; i<n-1; i+=2)    swap(arr[i], arr[i+1]);   
}

int main(){
	
    int arr[] = {20, 10, 8, 6, 4, 2};

    int size = sizeof(arr)/sizeof(arr[0]);

    wave(arr, size);
    print(arr, size);

    Wave(arr, size);
    print(arr, size);

	return 0;
}