#include <bits/stdc++.h>
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define inputArr(arr, n)   for( auto i = 0 ; i < n ; i++ )     cin >> arr[i]; 
#define inputVector(v, n)  for(auto i=0; i<n; i++) {int temp;    cin >> temp;    v.pb(temp);} 
#define inputDeque(d, n)   for(auto i=0; i<n; i++) {int temp;    cin >> temp;    d.pb(temp);} 
#define print(K)  for(auto i : K) {cout << i ;}  cout << endl; 
using namespace std;

// Arithmetic Operations of VERY VERY LARGE NUMBERS using DEQUE or ARRAY

void Difference(deque<int> l, deque<int> r){

    deque<int> ans;

    for (int i = r.size() - 1; i >= 0; i--){

        if (r[i] >= l[i])     ans.pf(r[i] - l[i]);
        else{
            r[i - 1]--;
            ans.pf(10 + r[i] - l[i]);
        }
    }

    int i = 0;
    while (ans[i] == 0)    ans.ppf();

    cout << R << " - " << L << " = " ;    
    print(ans);
}

int main(){

    string L, R;
    cout << "Enter L : ";    cin >> L;
    cout << "Enter R : ";    cin >> R;

    std::deque<int> l, r;

    for (int i = 0; i < R.size(); i++)    r.pb((int)(R[i] - '0'));

    for (int i = 0; i < L.size(); i++)    l.pb((int)(L[i] - '0'));
    while (l.size() < r.size())    l.pf(0);

    

    return 0;
}