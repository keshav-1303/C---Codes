#include <bits/stdc++.h>
using namespace std;

int trap(vector<int>& arr) {
    int left = 0, right = arr.size()-1;
    int leftMax = 0, rightMax = 0;
    int ans = 0;
    while(left <= right){
        if(arr[left] <= arr[right]){
            if(arr[left] >= leftMax)    leftMax = arr[left];
            else    ans += leftMax - arr[left];
            left++;
        }
        else{
            if(arr[right] >= rightMax)    rightMax = arr[right];
            else    ans += rightMax - arr[right];
            right--;
        }
    }
    return ans;
}