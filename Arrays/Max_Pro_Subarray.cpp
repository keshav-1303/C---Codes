#include <bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/studio/problems/subarray-with-maximum-product_6890008?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

int subarrayWithMaxProduct(vector<int> &arr){
	
	int pref = 1, suff = 0, maxPro = INT_MIN, n = arr.size();

	for(int i=0 ; i<n ; i++){
		if(pref == 0)	pref = 1;
		if(suff == 0)	suff = 1;
		
		pref = pref * arr[i];
		suff = suff * arr[n-i-1];

		maxPro = max(maxPro, max(pref, suff));
	}
	return maxPro;
}