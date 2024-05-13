#include <bits/stdc++.h>
using namespace std;

// Tabulation T.C = O(N*N), S.C = O(1) ------------------------------
int minJumps(int arr[], int n){
    vector<int> dp(n, 1e8);
    dp[n-1] = 0;
    
    for(int ind=n-2 ; ind>=0 ; ind--){
    
        int jump = 1e8;
        for(int i=ind+1 ; i<=min(ind+arr[ind], n-1) ; i++){
            jump = min(jump, dp[i]+1);
        }
        dp[ind] = jump;
    }
    
    return dp[0] >= 1e8 ? -1 : dp[0];
}

// Optimal T.C = O(N), S.C = O(1) ------------------------------------
int minJumps(int arr[], int n){
    
    int jump = 1;
    int step = arr[0];    // stores how much more it can jump
    int maxR = arr[0];    // stores max Reachable index for each i
    
    if(n == 1)   return 0;
    else if(arr[0] == 0)   return -1;
    else{
        
        for(int i=1 ; i<n ; i++){
            maxR = max(maxR, arr[i]+i);
            
            if(i == n-1)    return jump;

            step--;
            if(step == 0){
                jump++;
                step = maxR - i;
            }
            
            if(i >= maxR){
                return -1;
            }
        }
    }
}
