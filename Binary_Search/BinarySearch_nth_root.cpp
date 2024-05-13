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

double multiply(double mid, double n){
    int pro = 1;
    for(int i=0 ; i<n ; i++){
        pro = pro * mid;
    }
    return pro;
}

double nth_root(double x, double n){

    double precision = 1e-8;
    // for x precision set precision as 10^-(x+1) 

    double low = 1, high = x, mid;

    while(high - low > precision){
        mid = (high + low)/2;
        if(multiply(mid, n) < x){
            low = mid;
        }
        else{ 
            high = mid;
        }
    }

    return low;
}

int main(){

    double x;
    cout << "Enter number : ";    cin >> x;

    double n;
    cout << "Enter nth root : ";     cin >> n;

    // Time Complexity - n * O(N * log(10^precision));

    cout << nth_root(x, n) << endl;
    
    return 0;
}

