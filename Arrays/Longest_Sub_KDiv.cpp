#include <bits/stdc++.h>
using namespace std;

// Return longest subarray length divisible bt k

int longSubarrWthSumDivByK(int arr[], int n, int k){
	    
    map<int, int> prefSum;   // <sum, pos>
    int sum = 0, maxlen = 0;
    
    for(int i=0 ; i<n ; i++){
        
        sum = sum + arr[i];
        
        int rem = sum % k;
        if(rem < 0)   rem += k;    // for negative remainders
        
        if(rem == 0){
            maxlen = max(maxlen, i+1);
        }
        
        if(prefSum.find(rem) == prefSum.end()){
            prefSum[rem] = i+1;
        }
        else{
            maxlen = max(maxlen, i+1-prefSum[rem]);
        }
    }
    
    return maxlen;
}