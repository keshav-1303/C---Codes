#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1    

// T.C = O(N * logN), S.C = O(N);

int longestSubsequence(int n, int arr[]){
        
        vector<int> temp;
        temp.push_back(arr[0]);
        
        for(int i=1 ; i<n ; i++){
            if(arr[i] > temp.back()){
                temp.push_back(arr[i]);
            }
            else{
                int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
                temp[ind] = arr[i];
            }
        }
        
        return temp.size();
       
    }