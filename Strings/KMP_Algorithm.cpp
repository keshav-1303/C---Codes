#include <bits/stdc++.h>
using namespace std;

// Matches 2 strings in O(N + M) T.C
// https://www.youtube.com/watch?v=V5-7GzOfADQ

vector<int> search(string s2, string s1){
    int n = s1.size(), m = s2.size();
    vector<int> lps(m, 0);
    int i = 0, j = 1;
    while(j < m){
        while(i > 0 && s2[i] != s2[j]){
            i--;
        }
        if(s2[i] == s2[j]){
            lps[j] = i+1;
            i++;
        }
        j++;
    }

    vector<int> ans;
    i = 0, j = -1;
    while(i < n){
        if(j+1 < m && s1[i] == s2[j+1]){
            i++;
            j++;
        }
        if(j == m-1){   // s2 found
            ans.push_back(i-j);   // +1 for 1-based indexing
            j = lps[j]-1;
        }
        else if(i < n && s1[i] != s2[j+1]){
            if(j == -1)   i++;
            else    j = lps[j]-1;
        }
    }
    return ans;
}

