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

int main(){

    double x;
    cout << "Enter n : ";    cin >> x;

    double low = 1 , high = x , mid;

    double precision = 1e-6;
    // for x precision set precision as 10^-(x+1)

    while(high - low > precision){

        mid = (high + low)/2;

        if(mid * mid < x){
            low = mid;
        }
        else{ 
            high = mid;
        }
    }

    // Time Complexity - O(log(N * 10^precision));

    cout << low << endl;
    
    return 0;
}

