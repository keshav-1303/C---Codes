#include <bits/stdc++.h>
using namespace std;

// Time complexity : O(nlogn)
 
void merge(int *arr, int s, int e){

    int mid = (s + e)/2;
    int len1 = mid - s + 1;
    int len2 = e - mid;
  
    int L[len1], R[len2];
  
    /* Copy data to temp arrays L[] and R[] */
    for (int i=0; i<len1; i++)    L[i] = arr[s+i];

    for (int j=0; j<len2; j++)    R[j] = arr[mid+1+j];
  
    /* Merge the temp arrays back into arr[l..r]*/
    int i = 0; // Initial index of first subarray
    int j = 0; // Initial index of second subarray
    int k = s; // Initial index of merged subarray
    while (i<len1 && j<len2) {
        if (L[i] <= R[j])    arr[k++] = L[i++];
        
        else    arr[k++] = R[j++];
    }
  
    while (i < len1)    arr[k++] = L[i++];
    
    while (j < len2)    arr[k++] = R[j++];
}
  
void mergeSort(int *arr, int s, int e){
    
    if(s>=e)    return ;

    int mid = (e + s)/2;

    mergeSort(arr, s, mid);
    mergeSort(arr, mid+1, e);
    merge(arr, s, e);
}
  
void print(int *arr, int size){
    for (int i=0; i<size; i++)    cout << arr[i] << " ";
    cout << endl;
}

int main(){

    int arr[] = {1,4,5,2,7,2,7,5,3,9,3,9,2};
    int size = sizeof(arr)/sizeof(arr[0]);
  
    cout << "Given array is... \n";
    print(arr, size);
  
    mergeSort(arr, 0, size - 1);
  
    cout << "\nSorted array is... \n";
    print(arr, size);

    return 0;
}