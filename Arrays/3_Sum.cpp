#include <bits/stdc++.h>
using namespace std;

// Return all the unique triplets [ARR[i], ARR[j], ARR[k]] such that i != j, j != k and k != i 
// and their sum is equal to zero.

// https://www.codingninjas.com/studio/problems/three-sum_6922132?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

vector<vector<int>> triplet(int n, vector<int> &arr){

    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());   // THIS IS MUST.

    for(int i=0 ; i<n ; i++){

        if(i > 0 && arr[i] == arr[i-1])   continue;

        int j = i+1, k = n-1;

        while(j < k){
            if(arr[i] + arr[j] + arr[k] < 0){
                // if sum < 0 move j to right
                j++;
            }
            else if(arr[i] + arr[j] + arr[k] > 0){
                // if sum > 0 move k to left
                k--;
            }
            else{
                // Now sum = 0, so this triplet must come in ans;
                ans.push_back({arr[i], arr[j], arr[k]});
                j++;
                k--;

                while(j < k && arr[j] == arr[j-1])   j++;
                while(j < k && arr[k] == arr[k-1])   k--;
            }
        }
    }
    return ans;
}
