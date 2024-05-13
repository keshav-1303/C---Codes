// The sieve of Eratosthenes is one of the most efficient ways to find all primes smaller than n when n is smaller than 10 million or so 

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

// Find all primes in a range [a,b] taking a and b as input from user.
// Time Complexity : O(N log (log N))

void PrimeSieve(int n){

    vector<int> arr(100, 1);

    for(int i=2; i<=n; i++){
        if(arr[i] == 1){
            for(int j=i*i; j<=n; j+=i)    arr[j] = 0;
        }
    }

    for(int i=2; i<=n; i++){
        if(arr[i] == 1)    cout << i << " ";
    }

    cout << endl;
}

void PrimeSieve(int a, int b){

    vector<int> arr(b, 1);

    for(int i=2; i<=b; i++){
        if(arr[i] == 1){
            for(int j=i*i; j<=b; j+=i)    arr[j] = 0;
        }
    }

    for(int i=a; i<=b; i++){
        if(arr[i] == 1)    cout << i  << " ";
    }

    cout << endl;
}

int main(){

    int n;    cout << "Enter n : ";    cin >> n;
    cout << endl << "Prime Numbers between 1 to " << n << " are ...\n";
    PrimeSieve(n);    cout << endl;
    
    // int a, b;
    // cout << "START : ";     cin >> a;
    // cout << "END : ";     cin >> b;
    // cout << endl << "Prime Numbers between " << a << " to " << b << " are ...\n";
    // PrimeSieve(a, b);    cout << endl;

	return 0;
}