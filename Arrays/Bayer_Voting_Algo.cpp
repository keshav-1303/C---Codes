#include <bits/stdc++.h>
using namespace std;
// You are given an array 'a' of 'n' integers.
// A majority element in the array ‘a’ is an element that appears more than n/2 times.
// Find the majority element of the array.
// It is guaranteed that the array 'a' always has a majority element.

int majority_Element(vector<int> a) {
	
	// Bayer Moore's Voting Algo majority > n/2
	int el = 0, cnt = 0, n = a.size();

	for(int i=0 ; i<n ; i++){
		if(cnt == 0){
			cnt = 1;
			el = a[i];
		}
		else if(a[i] != el){
			cnt--;
		}
		else if(a[i] == el){
			cnt++;
		}
	}

	return el;
}

// For more than n/3 times.
vector<int> majorityElement(vector<int> a) {
	
	// Here we can have 2 elements
	int el1 = INT_MIN, el2 = INT_MIN, cnt1 = 0, cnt2 = 0, n = a.size();

	for(int i=0 ; i<a.size() ; i++){
		if(cnt1 == 0 && el2 != a[i]){
			cnt1 = 1;
			el1 = a[i];
		}
		else if(cnt2 == 0 && el1 != a[i]){
			cnt2 = 1;
			el2 = a[i];
		}
		else if(el1 == a[i])	cnt1++;

		else if(el2 == a[i])	cnt2++;
		
		else{
			cnt1--,cnt2--;
		}
	}

	// Manually check if el1 and el2 are valid
	vector<int> ans;
	cnt1 = 0, cnt2 = 0;
	for(int i=0 ; i<a.size() ; i++){
		if(a[i] == el1)	   cnt1++;
		if(a[i] == el2)	   cnt2++;
	}

	int mini = (int)(n/3) + 1;
	if(cnt1 >= mini)	ans.push_back(el1);
	if(cnt2 >= mini)	ans.push_back(el2);

	return ans;
}

