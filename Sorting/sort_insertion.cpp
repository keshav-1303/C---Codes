#include <bits/stdc++.h>
using namespace std;

// Time complexity : O(n*n)

void insertionsort(int *arr, int n){    //can be used when size of array is small

    for(int i=1 ; i<n ; i++){

        int curr = arr[i];
        int j = i - 1;

        for( ; j >= 0 ; j--){
            if( arr[j] > curr )    arr[j + 1] = arr[j];
            else    break;
        }

        arr[j + 1] = curr;
    }

    for(int i=0; i<n; i++)    cout << arr[i] << " ";
    cout << endl;
}

int main(){
	
    int arr[] = {1,4,5,2,7,2,7,5,3,9,3,9,2};

    int n = sizeof(arr)/sizeof(arr[0]);

    print(arr, n);

    insertionsort(arr, arr+n);
    
    print(arr, n);
    
	return 0;
}