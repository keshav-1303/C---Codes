#include <bits/stdc++.h>
using namespace std;

// Maxsum stores --> from index 0 to i, what is maximum sum we can get
// if we consider subarray including a[i].
// i.e in [x0, x1, x2, x3, ... a[i], ...., xn] it gives maximum sum of 
// subarray {x0, x1, x2, .... a[i]}.

void __________(int testcases){

    int n;   cin >> n;
    vector<int> v(n);
    for(int i=0 ; i<n ; i++){
        cin >> v[i];k
    }

    vector<int> nums = v;
    vector<int> maxsum (n);

    int sum = 0;
    int maxi = nums[0];

    for(int i=0 ; i<nums.size() ; i++){
        sum = sum + nums[i];      
        maxsum[i] = max(nums[i], sum);    // IMP
        if(sum < 0)    sum = 0;   
    }
    
    for(auto i : maxsum){
        cout << i << " ";
    }cout << endl;

}