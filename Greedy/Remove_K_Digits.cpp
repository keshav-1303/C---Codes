#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/remove-k-digits/?envType=daily-question&envId=2024-04-11
// Monotonic Stack
string removeKdigits(string num, int k) {
    int n = num.size();
    int len = n-k;
    stack<char> S;   S.push(num[0]);
    for(int i=1 ; i<n ; i++){
        while(k > 0 && !S.empty() && num[i] < S.top()){
            S.pop();
            k--;
        }
        S.push(num[i]);
    }
    while(S.size() > len)   S.pop();
    string ans = "";
    while(!S.empty()){
        ans += S.top();
        S.pop();
    }
    while(ans.size() > 0 && ans.back() == '0')    ans.pop_back();
    reverse(ans.begin(), ans.end());
    if(ans == "")   return "0";
    return ans;
}