#include <bits/stdc++.h>
#define pb push_back
#define ppb pop_back
#define inputVector(v, n)  for(auto i=0; i<n; i++) {int temp;    cin >> temp;    v.pb(temp);} 
#define print(K)  for(auto i : K) {cout << i << " ";}  cout << endl; 
#define ll long long int
using namespace std;

// Kadane's Algorithm is used to find MAXIMUM CONTIGUOUS SUBARRAY SUM

int NaiveApproach(vector<int> &nums){

    int n = nums.size(), maxsum = INT_MIN;

    for (int i=0 ; i<n ; i++){
        int sum = 0;
        for (int j=i ; j<n ; j++){
            sum += nums[j];
            maxsum = max(maxsum, sum);
        }
    }
    return maxsum;
}

int Kadane_Approach(vector<int> &nums){

    int sum = 0;
    int maxi = nums[0];

    for(int i=0 ; i<nums.size() ; i++){

        sum = sum + nums[i];      //step 1

        maxi = max(maxi, sum);    //step 2

        if(sum < 0)    sum = 0;   //step 3
    }
    return maxi;
}

int main(){
    
    vector<int> v{-2,-1};
    // vector<int> v{-1};

    cout << "Time Complexity : O(n*n)... " << NaiveApproach(v) << endl;

    cout << "Time Complexity : O(n)... " << Kadane_Approach(v) << endl;

	return 0;
}