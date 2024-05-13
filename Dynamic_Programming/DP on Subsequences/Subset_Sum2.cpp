// https://www.codingninjas.com/studio/problems/subset-sum-equal-to-k_1550954?leftPanelTab=1&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

#include <bits/stdc++.h> 
using namespace std;

// Space Optimised--------------------------------------------------------------

#include <bits/stdc++.h>

bool subsetSumToK(int n, int k, vector<int> v) {

    if(accumulate(v.begin(), v.end(), 0) == k){
        return 1;
    }

    vector<bool> prev(k+1, 0), curr(k+1, 0);
    
    prev[v[0]] = 1;

    prev[0] = curr[0] = 1;

    for(int ind=1 ; ind<n ; ind++){
        for(int sum=0 ; sum<=k ; sum++){

            bool notpick = prev[sum];
            bool pick = (sum >= v[ind]) ? prev[sum - v[ind]] : 0;

            curr[sum] = max(pick, notpick);
        }

		prev = curr;
    }

    return prev[k];
}

bool canPartition(vector<int> &arr, int n) {

    int sum = accumulate(arr.begin(), arr.end(), 0);

    if (sum & 1){
		return 0;
	}

    int target = sum/2;
	bool ans = subsetSumToK(n, sum/2, arr);

	return ans;
	
}
