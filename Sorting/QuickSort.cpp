#include <bits/stdc++.h>
using namespace std;
#define print(K)    for(auto i : K) {cout << i << " ";}  cout << endl; 

// Time complexity : O(nlogn)

int partition(int *arr, int low, int high){
    int pivot = arr[low]; 
    int k = high;
    for(int i=high ; i>low ; i--) {
        if(arr[i] > pivot)    swap(arr[i], arr[k--]);
    }
    swap(arr[low], arr[k]);
    return k;
}

// Random element as pivot
int partition_(int *arr, int start, int end){
    srand(time(0));
    int ind = start + rand()%(end-start);
    swap(arr[ind], arr[start]);
    return partition(arr, start, end);
}
 
void QuickSort(int *arr, int low, int high){
    if (low >= high)    return ;
    int p = partition_(arr, low, high);
    // int p = partition(arr, low, high);
    QuickSort(arr, low, p - 1);
    QuickSort(arr, p + 1, high);
}

int main(){

    int n = 8;    
    int arr[n] = {4, 6, 2, 5, 9, 7, 1, 3};    

    QuickSort(arr, 0, n-1);

    cout << endl << "Sorted Array is ..." << endl;    print(arr);
 
    return 0;
}
