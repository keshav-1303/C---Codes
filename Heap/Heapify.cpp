#include <bits/stdc++.h>
using namespace std;
#define maxsize 100
#define print(K)    for(auto i : K) {cout << i << " ";}  cout << endl; 

void heapify(int* arr, int n, int i){

    int largest = i;
    int leftchildindex = 2*i;
    int rightchildindex = 2*i + 1;

    if(leftchildindex < n && arr[largest] < arr[leftchildindex]){
        largest = leftchildindex;
    }

    if(rightchildindex < n && arr[largest] < arr[rightchildindex]){
        largest = rightchildindex;
    }

    // if largest has changed --> it means parent is smaller than children thus swap is needed.
    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);    // check if largest is again encountered with same problem.
    }
}

void Make_Heap(int *arr, int n){

    for(int i=n/2 ; i>0 ; i--){
        heapify(arr, n, i);
    }
}

int main(){

    int arr[6] = {-1, 54, 53, 55, 52, 50};

    cout << "\nBefore heapify --> " << endl;
    print(arr);

    Make_Heap(arr, 6);

    cout << "\nAfter heapify --> " << endl;
    print(arr);
    
    return 0;
}

