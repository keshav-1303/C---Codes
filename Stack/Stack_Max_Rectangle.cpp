// Find max area'd RECTANGLE with all 1's in a binary matrix

#include <bits/stdc++.h>
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
using namespace std;
#define inputArr(arr, n)   for( auto i = 0 ; i < n ;  i++ )     cin >> arr[i]; 
#define inputVector(v, n)  for(auto i=0; i<n; i++) {int temp;    cin >> temp;    v.pb(temp);} 
#define print(K)    for(auto i : K) {cout << i << " ";}  cout << endl; 
#define printmap(m)    for(auto i : m){ cout << i.first << " : " << i.second << endl; }
#define MAX 100


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

        area = max(area, length * breadth);
    }
    return area;
}
    
int maxArea(int** M, int n, int m) {
        
    vector<int> v(m, 0);
    for(int j=0 ; j<m ; j++){
        v[j] = v[j] + M[0][j];
    }
        
    int area = largestRectangleArea(v);
    
    for(int i=1 ; i<n ; i++){
        
        for(int j=0 ; j<m ; j++){
            v[j] = v[j] + M[i][j];
            if(M[i][j] == 0)    v[j] = 0;
        }
        
        int newArea = largestRectangleArea(v);
        
        area = max(area, newArea);
    }
        
    return area;
}

int main(){
    
    int m = 4, n = 4;

    int **arr = (int**)malloc(n * sizeof(int*));

    for(int i=0 ; i<n ; i++){
        arr[i] = (int*)malloc(m * sizeof(int));
    }

    int M[n][m] = {0, 1, 1, 0,
               1, 1, 1, 1,
               1, 1, 1, 1,
               1, 1, 0, 0};

    arr = M;

    cout << "MaxArea --> " << maxArea(M, n, m) << endl;

}
