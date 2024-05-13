#include <bits/stdc++.h>
using namespace std;

// To generate permutation of the array
void shuffle(int a[], int n){
	for (int i = 0; i < n; i++)
		swap(a[i], a[rand() % n]);
}

// Sorts array a[0..n-1] using Bogo sort
void bogosort(int a[], int n){
	// if array is not sorted then shuffle the array again
	while (!is_sorted(a, a+n))
		shuffle(a, n);
}

void printArray(int a[], int n){
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

int main(){

	int a[] = { 3, 2, 5, 1, 0, 4, 9, 78};
	int n = sizeof a / sizeof a[0];
	bogosort(a, n);
	printf("Sorted array :\n");
	printArray(a, n);
	return 0;
}
