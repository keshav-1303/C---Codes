#include <bits/stdc++.h>
using namespace std;

// Time Complexity : O(n*n)

int main(){
	
    int arr[] = {1,4,5,2,7,2,7,5,3,9,3,9,2};

    int n = sizeof(arr)/sizeof(arr[0]);

    print(arr, n);

    shellsort(arr, arr+n);
    
    print(arr, n);
    
	return 0;
}