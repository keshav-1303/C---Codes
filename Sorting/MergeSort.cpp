#include <iostream>
using namespace std;

// Merge two sorted subarrays L and M into arr
void merge(int arr[], int low, int mid, int high){

	// Create L ← A[p..q] and M ← A[q+1..r]
	int n1 = mid - low + 1;
	int n2 = high - mid;

	int L[n1], M[n2];

	for(int i=0 ; i<n1 ; i++){
		L[i] = arr[low+i];
	}
	for(int j=0 ; j<n2 ; j++){
		M[j] = arr[mid+1+j];
	}

	// Maintain current index of sub-arrays and main array
	int i, j, k;
	i = 0;
	j = 0;
	k = low;

	while (i < n1 && j < n2){
		if (L[i] <= M[j]){
			arr[k++] = L[i++];
		}
		else{
			arr[k++] = M[j++];
		}
	}

	// When we run out of elements in either L or M,
	// pick up the remaining elements and put in A[p..r]
	while (i < n1)	 arr[k++] = L[i++];
	while (j < n2)   arr[k++] = M[j++];
	
}

void mergeSort(int arr[], int low, int high){
	if (low < high){
		// m is the point where the array is divided into two subarrays
		int mid = low + (high-low)/2;

		mergeSort(arr, low, mid);
		mergeSort(arr, mid+1, high);

		// Merge the sorted subarrays
		merge(arr, low, mid, high);
	}
}

// Print the array
void printArray(int arr[], int size){
	for (int i=0 ; i<size ; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main(){
	int arr[] = {6, 5, 12, 10, 9, 1};
	int size = sizeof(arr) / sizeof(arr[0]);

	mergeSort(arr, 0, size - 1);

	cout << "Sorted array: \n";
	printArray(arr, size);
	return 0;
}