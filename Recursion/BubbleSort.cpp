#include <bits/stdc++.h>
using namespace std;

void sortArray(int *arr, int n){

    if(n==0 || n==1)    return ;

    for(int i=0; i<n-1; i++){
        if(arr[i] > arr[i+1])   swap(arr[i], arr[i+1]);
    }

    return sortArray(arr, n-1);
}

int main(){

	int arr[] = {1,2,7,8,5,3,4,6,2,4,8};
    int n = sizeof(arr)/sizeof(arr[0]);

    sortArray(arr, n);

    for(int i=0; i<n; i++)    cout << arr[i] << " ";
    cout << endl;

	return 0;
}