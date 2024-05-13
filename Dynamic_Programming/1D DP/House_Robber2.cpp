#include <bits/stdc++.h> 
using namespace std;

long long int maximumNonAdjacentSum(vector<int> &nums){

    long long int n = nums.size();
    
    long long int prev2 = nums[0];
    long long int prev1 = max(nums[0], nums[1]);

    for(long long int i=2 ; i<n ; i++){

        long long int pick = prev2 + nums[i];
        long long int notpick = prev1;

        long long int curr = max(pick, notpick);

        prev2 = prev1;
        prev1 = curr;
    }
    
    return prev1;
}

long long int houseRobber(vector<int>& valueInHouse){

    long long int n = valueInHouse.size();

    if(n == 1){
        return valueInHouse[0];
    }

    vector<int> temp1, temp2;

    for(long long int i=0 ; i<n ; i++){
        if(i != 0)    temp1.push_back(valueInHouse[i]);
        if(i != n-1)    temp2.push_back(valueInHouse[i]);
    }

    return max(maximumNonAdjacentSum(temp1), maximumNonAdjacentSum((temp2)));
}