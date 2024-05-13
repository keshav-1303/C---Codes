#include <bits/stdc++.h>
using namespace std;

// Given an array of integers 'ARR’ of size ‘N’. Replace each element of this array with its corresponding rank and return the array.
// eg - [1 2 6 9 2] => [1 2 3 4 2]

vector<int> replaceWithRank(vector<int> &arr, int n) {
    map<int, int> mp;    // <element, rank>
    for(int i=0 ; i<n ; i++){
        mp[arr[i]] = 0;
    }
    int cnt = 1;
    for(auto &i : mp){
        i.second = cnt++;
    }
    for(int i=0 ; i<n ; i++){
        arr[i] = mp[arr[i]];
    }
    return arr;
}
