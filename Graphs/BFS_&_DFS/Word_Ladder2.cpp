#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/word-ladder-ii/

// My Attempt (TLE at test 32/36)
vector<vector<string>> findLadders(string start, string end, vector<string>& List) {
    queue<vector<string>> q;
    q.push({start});

    set<string> S (List.begin(), List.end());
    S.erase(start);   // erase elememts instead of using visited array

    vector<vector<string>> ans;
    int mini = 500;   // bec upper limit is given as 500

    while(!q.empty()){
        vector<string> temp = q.front();
        q.pop();
        string str = temp.back();
        S.erase(str);
        if(temp.size() > mini)   break;
        
        if(str == end){
            mini = temp.size();
            ans.push_back(temp);
        }
    
        for(int i=0 ; i<str.size() ; i++){
            char original = str[i];
            for(char j='a' ; j<='z' ; j++){
                str[i] = j;
                if(S.find(str) != S.end()){
                    temp.push_back(str);
                    q.push(temp);
                    temp.pop_back();
                }
            }
            str[i] = original;
        }
    }
    return ans;
}