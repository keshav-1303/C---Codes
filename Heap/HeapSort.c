#include <stdio.h>
#include <stdlib.h>

void swap(int *i, int *j){
    int temp = *i;
    *i = *j;
    *j = temp;
}

void heapify(int *arr, int size, int i){

    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if(arr[left] > arr[largest] && left < size){
        largest = left;
    }

    if(arr[right] > arr[largest] && right < size){
        largest = right;
    }

    if(largest != i){
        swap(&arr[i], &arr[largest]);
        heapify(arr, size, largest);
    }
}

void HeapSort(int *arr, int size){

    if(size == 1)    return ;

    swap(&arr[1], &arr[size-1]);
    size--;

    heapify(arr, size, 1);
    HeapSort(arr, size);    
}

int main(){

    int arr[6] = {-1, 70, 60, 55, 45, 50};

    printf("\nOriginal array --> \n");
    print(arr, 6);

    HeapSort(arr, 6);

    printf("\nAfter HeapSort --> \n");
    print(arr, 6);
}