#include<bits/stdc++.h>
using namespace std;
#define print(K)    for(auto i : K) {cout << i << " ";}  cout << endl; 

// WAP to print this pattern for any value of n.
// 5 5 5 5 5 5 5 5 5 
// 5 4 4 4 4 4 4 4 5 
// 5 4 3 3 3 3 3 4 5 
// 5 4 3 2 2 2 3 4 5 
// 5 4 3 2 1 2 3 4 5 
// 5 4 3 2 2 2 3 4 5 
// 5 4 3 3 3 3 3 4 5 
// 5 4 4 4 4 4 4 4 5 
// 5 5 5 5 5 5 5 5 5

int main(){ 

    cout << "Enter n : ";

    int n;     cin >> n;

    vector<int> v (2*n-1, n);

    cout << endl;

    int i = 0;

    for( ; i<n ; i++){
        if(i == 0){
            print(v);
        }
        else{
            for(int j=i ; j<2*n - i - 1 ; j++)    v[j]--;
            print(v);
        }
    }

    i--;

    for( ; i>0 ; i--){
        if(i == 0){
            print(v);
        }
        else{
            for(int j=i ; j<2*n - i - 1 ; j++)    v[j]++;
            print(v);
        }
    }
    cout << endl;

    return 0;
}