// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/

#include <bits/stdc++.h> 
using namespace std;

// Max possible ans is len(string 1) + len(string 2), what for minimum?
// Number of insertions will be len(string 1) - lcs(string1, string2);
// Number of deletions will be len(string 2) - lcs(string1, string2);
// Thus, ans = insertions + deletions.

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

int canYouMake(string string1, string string2){

    int insertions = string1.size() - lcs(string1.size(), string2.size(), string1, string2);
    int deletions = string2.size() -  lcs(string1.size(), string2.size(), string1, string2);

    return insertions + deletions;
}

