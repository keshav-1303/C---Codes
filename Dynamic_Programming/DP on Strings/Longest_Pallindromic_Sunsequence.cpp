// https://leetcode.com/problems/longest-palindromic-subsequence/description/

#include <bits/stdc++.h> 
using namespace std;

int lcs(int n, int m, string s1, string s2){
    
    vector<int> prev(m+1, 0), curr(m+1, 0);
    
    for(int ind1=1 ; ind1<=n ; ind1++){
        for(int ind2=1 ; ind2<=m ; ind2++){
            
            if(s1[ind1-1] == s2[ind2-1]){
                curr[ind2] = 1 + prev[ind2-1];
                // bec if matched we dont need to check that in again.
            }
            else{
                curr[ind2] = 0 + max(prev[ind2], curr[ind2-1]);
            }
        }
        
        prev = curr;
    }
    
    return curr[m];
}

int longestPalindromeSubseq(string s) {

    // if we find LCS of strings of S and rev(S)
    // it will give the Longest Palindromic Subsequence.

    string s2 = s;
    reverse(s.begin(), s.end());

    return lcs(s.size(), s.size(), s, s2);
}
