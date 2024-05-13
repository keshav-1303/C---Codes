// Given an array arr[] denoting heights of N towers and a positive integer K.

// For each tower, you must perform exactly one of the following operations exactly once.

// Increase the height of the tower by K
// Decrease the height of the tower by K
// Find out the minimum possible difference between the height of the shortest and tallest towers after you have modified each tower.

#include <bits/stdc++.h>
using namespace std;

int getMinDiff(int arr[], int n, int k) {
    
    sort(arr, arr + n);
    
    int largest = arr[n-1] - k;
    int smallest = arr[0] + k;
    
    int ans = arr[n-1] - arr[0];
    
    int mini, maxi;
    
    for(int i=0 ; i<n-1 ; i++){
        mini = min(smallest, arr[i+1] - k);
        maxi = max(largest, arr[i] + k);
        
        if(mini < 0)    continue;
        ans = min(maxi - mini, ans);
    }
    
    return ans;
    
}

int main() {

    int n, k;     cin >> k;     cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << getMinDiff(arr, n, k) << endl;
    
    return 0;
}