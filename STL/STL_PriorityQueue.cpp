// a priority queue is about five times faster than a multiset as well as set

// A C++ priority queue is a type of container adapter, specifically designed such that the first element of the queue is either the greatest or the smallest of all elements in the queue, and elements are in non-increasing or non-decreasing orde

#include <iostream>
#include <iterator>
#include <queue>
using namespace std;
#define print(K)    for(auto i : K) {cout << i << " ";}  cout << endl; 

void showpq(priority_queue<int, vector<int>, greater<int> > gq){
	priority_queue<int, vector<int>, greater<int> > g = gq;
	while (!g.empty()) {
		cout << ' ' << g.top();
		g.pop();
	}
	cout << '\n';
}

void showArray(int* arr, int n){
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;
}

int main(){
	int arr[6] = { 10, 2, 4, 8, 6, 9 };

	// defining max heap priority queue
	priority_queue<int> pq;

	// printing array
	cout << "Array: ";
	print(arr);
	for (int i = 0; i < 6; i++) {
		pq.push(arr[i]);
	}

	// printing priority queue
	cout << "Priority Queue: ";
	while (!pq.empty()) {
		cout << pq.top() << ' ';
		pq.pop();
	}

// min heap for priority queue

	int arr1[6] = { 10, 2, 4, 8, 6, 9 };
	priority_queue<int, vector<int>, greater<int> > gquiz(arr1, arr1 + 5);

	cout << "Array: ";
	showArray(arr1, 6);

	cout << "Priority Queue : ";
	showpq(gquiz);

	return 0;
}


