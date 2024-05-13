#include <bits/stdc++.h>
using namespace std;

//approach 1 (brute force approach);
int solve(vector<int> &weight, vector<int> &value, int index, int capacity){
	// base case;
	if (index == 0){
		if (weight[index] <= capacity)
			return value[0];
		else
			return 0;
	}

	int include = 0;
	if (weight[index] <= capacity)
		include = value[index] + solve(weight, value, index - 1, capacity - weight[index]);

	int exclude = solve(weight, value, index - 1, capacity);

	return max(include, exclude);
}

//Memoization--------------------------------------------------------
int solve1(vector<int> &weight, vector<int> &value, int index, int capacity,vector<vector<int>> &dp) {
    // base case;
    if (index == 0) {
        if (weight[index] <= capacity)
            return value[0];
        else
            return 0;
    }
    //step 3;
    if (dp[index][capacity] != -1)
        return dp[index][capacity];

    int include = 0;
    if (weight[index] <= capacity)
        include = value[index] + solve1(weight,value,index-1,capacity-weight[index],dp);

    int exclude = solve1(weight,value,index-1,capacity,dp);

    //step 2;
    dp[index][capacity] = max(include,exclude);
    return dp[index][capacity];
}


//Tabulation-----------------------------------------------------------------
int solve3(vector<int> &weight, vector<int> &value, int n, int capacity) {
	//step 1;
	vector<vector<int>> dp(n,vector<int>(capacity+1,0));

	//step 2; implement base case;
	//index == 0 means 0th row
	for (int w = weight[0];w <= capacity;w++){
		if (weight[0] <= capacity){
			dp[0][w] = value[0];
		}
		else	
			dp[0][w] = 0;
	}

	//step 3 : iterative fxn;
	for (int i =1;i < n;i++){
		for (int w = 0;w <= capacity;w++){
			int include = 0;
			if (weight[i] <= w){
				include = value[i] + dp[i-1][w-weight[i]];
			}
			int exclude = 0 + dp[i-1][w];
			dp[i][w] = max(include,exclude);
		}
	}
	return dp[n-1][capacity];
}

//space optimisation------------------------------------------------------------
int solve4(vector<int> &weight, vector<int> &value, int n, int capacity) {
	
	//step 1;
	vector<int> prev(capacity+1,0);

	//step 2; implement base case;
	//index == 0 means 0th row
	for (int w = weight[0];w <= capacity;w++){
		if (weight[0] <= capacity){
			prev[w] = value[0];
		}
		else	
			prev[w] = 0;
	}

	//step 3 : iterative fxn;
	for (int i=1 ; i<n ; i++){

		vector<int> curr(capacity+1,0);

		for (int w = 0;w <= capacity;w++){
			int include = 0;
			if (weight[i] <= w){
				include = value[i] + prev[w-weight[i]];
			}
			int exclude = 0 + prev[w];
			curr[w] = max(include,exclude);
		}
        
		prev = curr;
	}

	return prev[capacity];
}

// Most Space Optimised------------------------------------------------------- 
int knapsack(vector<int> weight, vector<int> value, int n, int capacity) {

	//step 1;
	vector<int> curr(capacity+1,0);

	//step 2; implement base case;
	//index == 0 means 0th row
	for (int w = weight[0];w <= capacity;w++){
		if (weight[0] <= capacity){
			curr[w] = value[0];
		}
		else	
			curr[w] = 0;
	}

	//step 3 : iterative fxn;
	for (int i=1 ; i < n ; i++){
		for (int w = capacity ; w >= 0 ; w--){
			int include = 0;
			if (weight[i] <= w){
				include = value[i] + curr[w-weight[i]];
			}
			int exclude = 0 + curr[w];
			curr[w] = max(include,exclude);
		}
	}

	return curr[capacity];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
	return solve(weight,value,n-1,maxWeight);
}