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

// https://practice.geeksforgeeks.org/problems/josephus-problem/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

int solve(vector<int> &v, int k, int index){

    if(v.size() == 1)    return v[0];

    index = (index + k) % v.size();

    v.erase(v.begin() + index);

    solve(v, k, index);
}

int main(){

    int N, k;

    cout << "\nEnter n : ";     cin >> N;
    cout << "Enter k : ";     cin >> k;

    // N = 3, k = 2;     // expected ans is 3

    vector<int> v;

    for(int i=1 ; i<=N ; i++){
        v.pb(i);
    }

    int index = 0;
    k--;

    cout << "\nPerson at position " << solve(v, k, index) << " survives\n" << endl;
 
    return 0;
}

