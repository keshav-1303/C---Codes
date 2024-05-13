/* Given an array A[] consisting of only 0s, 1s, and 2s. The task is to write a function that sorts the given array. The functions should put all 0s first, then all 1s and all 2s in last.(NOT BY USING SORT)

This problem is also the same as the famous “Dutch National Flag problem”. The problem is as follows:

Given N balls of colour red, white or blue arranged in a line in random order. You have to arrange all the balls such that the balls with the same colours are adjacent with the order of the balls, with the order of the colours being red, white and blue (i.e., all red coloured balls come first then the white coloured balls and then the blue coloured balls).                                                                         */

#include <bits/stdc++.h>
using namespace std;

void print(int *arr, int n){
    for(int i=0; i<n; i++)    cout << arr[i] << " ";
    cout << endl;
}

void dnfSort(int *arr, int n){

    int index0=0, index1=0, index2=0;
    for(int i=0; i<n; i++){
        
    }
    
}

int main(){

    int arr[] = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};

    int n = sizeof(arr)/sizeof(arr[0]);

    dnfSort(arr, n);
    print(arr, n);
	
	return 0;
}