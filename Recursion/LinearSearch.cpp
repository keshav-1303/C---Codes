#include <bits/stdc++.h>
using namespace std;

int LinearSearch(int *arr, int size, int k){

    if(size == 0)    return -1;

    if(arr[0] == k)    return (int)&arr[0];

    else    LinearSearch(arr+1, size-1, k);
}

int main(){
	
	int arr[] = {1,2,3,4,5,6,7,8,9};

	int n = sizeof(arr)/sizeof(int);

    cout << "Array is {1,2,3,4,5,6,7,8,9}...\n";
    int key;    cout << "Enter key : ";    cin >> key;

    int ans = LinearSearch(arr, n, key);

    if(ans == -1)   cout << "Element Not Found!!!" << endl;
    else    cout << "Element found at index " << (ans - (int)&arr[0])/sizeof(int) << endl;

	return 0;
}