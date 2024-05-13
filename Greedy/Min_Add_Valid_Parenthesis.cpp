#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
int minAddToMakeValid(string s) {
    int cnt = 0;
    stack<char> S;
    for(int i=0 ; i<s.size() ; i++){
        if(s[i] == '('){
            S.push(s[i]);
        }
        else if(s[i] == ')'){
            if(!S.empty() && S.top() == '(')   S.pop();
            else    cnt++;
        }
    }
    cnt += S.size();
    return cnt;
}