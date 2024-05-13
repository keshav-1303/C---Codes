#include <bits/stdc++.h>
using namespace std;

// Time complexity : O(n*n)

void bubblesort(int *arr, int n){    //ith largest element gets allocated at right in every round

    for(int j=0; j<n-1; j++){
        for(int i=0; i<n-1; i++){
            if(arr[i+1] < arr[i])    swap(arr[i], arr[i+1]);
        }
    }

    for(int i=0; i<n; i++)    cout<<arr[i]<<" ";
    cout<<endl;
}

int main(){

    int arr[] = {1,4,5,2,7,2,7,5,3,9,3,9,2};

    int n = sizeof(arr)/sizeof(arr[0]);

    print(arr, n);

    bubblesort(arr,n);
    
    print(arr, n);
 
	return 0;
}