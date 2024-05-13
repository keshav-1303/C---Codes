#include <bits/stdc++.h>
using namespace std;

// BEST SOLUTION -->
// https://www.youtube.com/watch?v=dJ7sWiOoK7g

// https://leetcode.com/problems/jump-game/
// Return IF IS IT POSSIBLE to reach from index 1 to n
bool canJump(vector<int>& arr) {
    int n = arr.size();
    int left = 0, right = 0;
    while(right < n-1){
        if(left > right)    return 0;
        int maxi = 0;
        for(int i=left ; i<=right ; i++){
            maxi = max(arr[i]+i, maxi);
        }
        left = right+1;
        right = maxi;
    }
    return 1;
}

// https://leetcode.com/problems/jump-game-ii/
// Return MINIMUM JUMPS to reach from index 1 to n
int jump(vector<int>& arr) {
    int cnt = 0, n = arr.size();
    int left = 0, right = 0;
    while(right < n-1){
        int maxi = 0;
        for(int i=left ; i<=right ; i++){
            maxi = max(arr[i]+i, maxi);
        }
        left = right+1;
        right = maxi;
        cnt++;
    }
    return cnt;
}