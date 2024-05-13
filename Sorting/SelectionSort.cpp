#include <bits/stdc++.h>
using namespace std;

// Time complexity : O(n*n)

void selectionsort(int *arr, int n){    //can be used when size of array is small
//in each round smallest element is placed at first

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[i])    swap(arr[i],arr[j]);
        }
    }

    for(int i=0; i<n; i++)    cout<<arr[i]<<" ";
    cout<<endl;
}

int main(){

    int n;    cout<<"Enter Number of elements : ";    cin>>n;

	int arr[n];
    for(int i=0; i<n; i++){
        cout<<"Enter element "<<i+1<<": ";
        cin>>arr[i];
    }

    selectionsort(arr, n); 
	return 0;
}