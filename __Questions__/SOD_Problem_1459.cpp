// https://www.codechef.com/problems/SOD3?tab=submissions

#include <bits/stdc++.h>
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define inputArr(arr, n)   for( auto i = 0 ; i < n ; i++ )     cin >> arr[i]; 
#define inputVector(v, n)  for(auto i=0; i<n; i++) {int temp;    cin >> temp;    v.pb(temp);} 
#define inputDeque(d, n)   for(auto i=0; i<n; i++) {int temp;    cin >> temp;    d.pb(temp);} 
#define inputSet(s, n)   for(auto i=0; i<n; i++) {int temp;    cin >> temp;    s.insert(temp);} 
#define print(K)  for(auto i : K) {cout << i << " ";}  cout << endl; 
#define MOD 1000000007
#define PI 3.14159265359
#define ll long long int
using namespace std;

void divby3(deque<int> v){
    
    deque<int> ans;
    
}

ll sod(int n){
    ll sod = 0;
    while(1){
        int r = n % 10;
        n = n / 10;
        sod += r;
        if(n == 0)   break;
    }
    return sod;
}

int main(){
    int T;    cin >> T;
    while(T--){
        
        string L, R;    cin >> L >> R;
        
        std::deque<int> l, r;
        
        for(int i=0; i<R.size(); i++)    r.pb( (int)(R[i] - '0') );
        
        for(int i=0; i<L.size(); i++)    l.pb( (int)(L[i] - '0') );
        while(l.size() < r.size())    l.pf(0);
        
        deque<int> ans;
        
        for(int i=r.size()-1; i>=0; i--){
            if(r[i] >= l[i])    ans.pf(r[i] - l[i]);
            else{
                r[i-1]--;
                ans.pf(10 + r[i] - l[i]);
            }
        }
        
        int i = 0;
        while(ans[i] == 0)    ans.ppf();
        
        
        
        print(ans);
        
    }
	return 0;
}