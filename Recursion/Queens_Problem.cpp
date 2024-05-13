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

// : the number of ways to place two non-attacking queens on an n × n chessboard

int main(){

    // q(n) = q(n − 1) + 2*(n − 1)(n - 1)(n − 2),
    // which provides an O(n) solution to the problem.
    
    // Finally, it turns out that there is also a closed - form formula 
    // q(n) = pow(n,4)/ 2 − 5*pow(n,3)/3 + 3*pow(n,2)/2 − n/3,
    // which can be proved using induction and the recursive formula.Using this formula,
    // we can solve the problem in O(1) time

    int n;    cin >> n;

    int q = pow(n,4)/ 2 - 5*pow(n,3)/3 + 3*pow(n,2)/2 - n/3;

    cout << q << endl;

    return 0;
}