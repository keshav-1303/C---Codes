#include <bits/stdc++.h>
using namespace std;
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

void HeapSort(int *arr, int size){

    if(size == 1){
        return ;
    }

    swap(arr[1], arr[size - 1]);    // STEP 1
    size--;

    heapify(arr, size, 1);    // STEP 2

    HeapSort(arr, size);
}

int main(){

    int arr[6] = {-1, 70, 60, 55, 45, 50};

    cout << "\nOriginal array --> " << endl;
    print(arr);

    HeapSort(arr, 6);

    cout << "\nAfter HeapSort --> " << endl;
    print(arr);
}