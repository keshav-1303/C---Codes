#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/word-ladder/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=word-ladder

// T.C = wordList.size() * word.size() * 26;

int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
    set<string> s (wordList.begin(), wordList.end());
    queue<pair<string, int>> q;
    q.push({startWord, 1});
    
    int len = startWord.size();
    
    while(!q.empty()){
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();
        
        if(word == targetWord)    return steps;
        // if any possible transformation found, function will end here
        
        for(int i=0 ; i<len ; i++){
            char original = word[i];
            for(char ch='a' ; ch<='z' ; ch++){
                word[i] = ch;
                if(s.find(word) != s.end()){    // matlab valid transformation hai
                    s.erase(word);
                    q.push({word, steps+1});
                }
            }
            word[i] = original;
        }
    }
    // if reaches here, no transformation is possible.
    return 0;
}