#include <bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/studio/problems/longest-string-chain_3752111?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1

bool compare(string &s1, string &s2){
    // remember s1 is the greater guy.
    if(s1.size() != s2.size() + 1)   return false;
    int first = 0, second = 0;

    while(first < s1.size()){
        if(s1[first] == s2[second]){
            first++;
            second++;
        }
        else{
            first++;
        }
    }

    if(first == s1.size() && second == s2.size())   return true;
    else    return false;
}

bool cmp(string &s1, string &s2){
    return (s1.size() < s2.size());
}

int longestStrChain(vector<string> &arr){
    
    int n = arr.size();

    vector<int> dp(n, 1);
    vector<int> hash(n, 0);

    iota(hash.begin(), hash.end(), 0);   // hash[i] = i, for all i
    int maxi = 1, maxValInd = 0;

    sort(arr.begin(), arr.end(), cmp);   // bec order doesnot matter.
    // i.e we csn pick 1st from ind 3 and 2nd from index 1.

    for(int ind = 0; ind < n; ind++){
        for(int prev = 0; prev < ind; prev++){
            if(compare(arr[ind], arr[prev]) && dp[ind] < 1+dp[prev]){
                dp[ind] = 1 + dp[prev];
                hash[ind] = prev;
            }
        }
        if(dp[ind] > maxi){
            maxi = dp[ind];
            maxValInd = ind;
        }
    }

    vector<string> chain;
    chain.push_back(arr[maxValInd]);
    while(hash[maxValInd] != maxValInd){
        maxValInd = hash[maxValInd];
        chain.push_back(arr[maxValInd]);
    }

    cout << "Longest String Chain is ..." << endl;
    reverse(chain.begin(), chain.end());
    for(auto i : chain){
        cout << i << " ";
    }
    cout << endl;
    
    return maxi;
}