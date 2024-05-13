#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/largest-rectangle-in-histogram/

vector<int> previousSmallerElement(vector<int> &arr, int n){
    vector<int> ans(n);
    stack<int> s;    s.push(-1);
    for(int i=0 ; i<n ; i++){
        while(s.top() != -1  &&  arr[s.top()] >= arr[i]){
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }

    return ans;
}

vector<int> nextSmallerElement(vector<int> &arr, int n){
    vector<int> ans(n);
    stack<int> s;    s.push(-1);
    for(int i=n-1 ; i>=0 ; i--){
        while(s.top() != -1  &&  arr[s.top()] >= arr[i]){
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }

    return ans;
}

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    vector<int> prev = previousSmallerElement(heights, n);
    vector<int> next = nextSmallerElement(heights, n);
    int area = INT_MIN;
    for(int i=0 ; i<n ; i++){
        next[i] = (next[i] == -1) ? n : next[i];    
        // for cases like [ 2 2 2 2 ]
        //when next SE not found breadth can go upto n
        int length = heights[i];
        int breadth = next[i] - prev[i] - 1;
        // cout << length << " " << breadth << endl;
        area = max(area, length * breadth);
    }
    return area;
    
}

int main(){

    vector<int> v = { 2,1,5,6,2,3};
    // vector<int> v = { 2,4};

    cout << "Largest Histogram Area : " << largestRectangleArea(v) << endl;
}
    
    