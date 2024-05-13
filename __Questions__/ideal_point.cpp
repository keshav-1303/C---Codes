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

int isAns(vector<int> &l, vector<int> &r, int k){

    vector<int>::iterator i = max_element(l.begin(), l.end());    int left = *i;
    vector<int>::iterator it = min_element(r.begin(), r.end());    int right = *it;

    // cout << "left is " << left << endl;
    // cout << "right is " << right << endl;

    cout << "l is now ";
    print(l);
    cout << "r is now ";
    print(r);

    if(k >= left  &&  k <= right)     return 1;
    else    return 0;
}

int isCorrect(vector<int> &l, vector<int> &r, int k, int i){

    vector<int> l1 = l;
    vector<int> r1 = r;

    l1.erase(l1.begin()+i);
    r1.erase(r1.begin()+i);

    // print(l1);
    // print(r1);

    return isAns( l1, r1, k );
}

int main(){
    int T;    cin >> T;
    while(T--){

        int n, k;     cin >> n >> k;
        vector<int> l, r;

        for(int i=0 ; i<n ; i++){
            int li, ri;    cin >> li >> ri;
            l.pb(li);
            r.pb(ri);
        }

        // print(l);
        // print(r);

        int check = 0;

        if(  isAns(l, r, k) == 1  ){
            check = 1;
        }        

        // for(int i=0 ; i<n && check==0 ; i++){
        //     if(  isCorrect(l, r, k, i) == 1  ){
        //         check = 1;
        //         break;
        //     }
        // }
        
        if(check)    cout << "YES" << endl;
        else    cout << "NO" << endl;

    }
    return 0;
}