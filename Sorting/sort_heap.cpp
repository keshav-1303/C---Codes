// Time complexity : O(logn)

#include <bits/stdc++.h>
using namespace std;

int main(){
	
    int arr[] = {1,4,5,2,7,2,7,5,3,9,3,9,2};

    int n = sizeof(arr)/sizeof(arr[0]);

    print(arr, n);

    heapsort(arr, 0, n-1);
    
    print(arr, n);
    
	return 0;
}