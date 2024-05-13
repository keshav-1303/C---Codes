#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/reveal-cards-in-increasing-order/description/?envType=daily-question&envId=2024-04-10

vector<int> deckRevealedIncreasing(vector<int>& deck) {
    int n = deck.size();
    if(n == 1)   return deck;
    sort(deck.begin(), deck.end());
    // skip 1 blank space and insert in next, this will give us the order
    vector<int> ans(n, 0);
    queue<int> q;
    for(int i=0 ; i<n ; i++)    q.push(i);

    int ind = 0;
    bool skip = 0;
    while(!q.empty()){
        if(!skip){
            ans[q.front()] = deck[ind++];
            q.pop();
            skip = 1;
        }
        else{
            int ind = q.front();
            q.pop();
            q.push(ind);
            skip = 0;
        }
    }
    return ans;
}