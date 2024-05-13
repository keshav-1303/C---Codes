#include <bits/stdc++.h>
using namespace std;

int BinarySearch(int *arr, int n, int k, int s, int e){ 

    int mid = (s+e)/2;

    if(s>e)    return -1;

    if(arr[mid] == k)   return (int)&arr[mid];

    else{
        if(arr[mid] > k){    
            e = mid - 1;
            return BinarySearch(arr, n, k, s, e);
        }
        else{
            s = mid + 1;
            return BinarySearch(arr, n, k, s, e);
        }
    }
}

int main(){
	
	int arr[] = {1,2,3,4,5,6,7,8,9};

	int n = sizeof(arr)/sizeof(int);

    cout << "Array is {1,2,3,4,5,6,7,8,9}...\n";
    int key;    cout << "Enter key : ";    cin >> key;

    int ans = BinarySearch(arr, n, key, 0, n-1);

    if(ans == -1)   cout << "Element Not Found!!!" << endl;
    else    cout << "Element found at index " << (ans - (int)&arr[0])/sizeof(int) << endl;

	return 0;
}