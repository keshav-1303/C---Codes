#include <bits/stdc++.h>
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define inputArr(arr, n)   for( auto i = 0 ; i < n ; i++ )     cin >> arr[i]; 
#define inputVector(v, n)  for(auto i=0; i<n; i++) {int temp;    cin >> temp;    v.pb(temp);} 
#define inputDeque(d, n)   for(auto i=0; i<n; i++) {int temp;    cin >> temp;    d.pb(temp);} 
#define inputSet(s, n)   for(auto i=0; i<n; i++) {int temp;    cin >> temp;    s.insert(temp);} 
#define print(K)    for(auto i : K) {cout << i << " ";}  cout << endl; 
#define printmap(m)    for(auto i : m){ cout << i.first << " : " << i.second << endl; }
#define MOD 1000000007
#define PI 3.14159265359
#define ll long long int
using namespace std;

int accum(vector<int> v, int s, int e){
    int sum = 0;
    int i = s;
    while(1){
        sum += v[i];
        if(i == e)    break;
        i++;
    }
    return sum;
}

int main(){
    
    ios::sync_with_stdio(0);   
    cin.tie(0);   
   
    #ifndef ONLINE_JUDGE   
    freopen("input.txt", "r", stdin);   
    // freopen("output.txt", "w", stdout);   
    #endif   

    int T;    cin >> T;
    while(T--){

        int m;    cin >> m;
        vector<int> num;
        vector<int> v;

        for(int i=0 ; i<m ; i++){

            int n;    cin >> n;
            num.pb(n);

            inputVector(v, n);
        }

        print(v);
        print(num);

        int n = v.size();   int c = 0;

        for(int i=0 ; i<n ; i++){

            cout << "is " << v[i] << " present--> " << binary_search(v.begin()+i, v.end()+1, v[i]) << endl;

            if( binary_search(v.begin()+i, v.end()+1, v[i]) == 0 ){
                cout << "**" << v[i] << "**";
                cout << "i was " << i << endl;
                i = accum(num, 0, c) - 1;
                cout << "i is now " << i << endl;
                c++;
                
            }

            // if(i > num[c])     c++;
            // cout << "c is now " << c << endl;
        }

        cout << endl;
    }
    return 0;
}