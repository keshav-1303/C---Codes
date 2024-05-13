//https://codeforces.com/problemset/problem/1294/C

#include <bits/stdc++.h>
using namespace std;
#define ll long long

//**************************************************************************************************************************

bool isprime(ll n){
    for(ll i=2 ; i<=sqrt(n) ; i++){
        if(n % i == 0){
            return 0;
        }
    }
    return (n == 1) ? 0 : 1;
}

// Suppose a < b < c
// . Let's try to minimize a and maximize c
// . Let a be the minimum divisor of n greater than 1
// . Then let b be the minimum divisor of n/a that isn't equal a and 1
// . If n/(a*b) isn't equal a, b as well as 1 then the answer is "YES", otherwise the answer is "NO".

void solve(){

    int n;    cout << "Enter n : ";    cin >> n;

    if(isprime(n)){
        cout << "NO" << endl;
        return ;
    }

    int a = n, b = n, c = n;

    for (int i=2 ; i<=sqrt(n) ; i++){
        if (n % i == 0){
            a = i;
            break;
        }
    }

    n = n / a;

    for (int i=2; i<=sqrt(n) ; i++){
        if (n % i == 0 && i != a){
            b = i;
            break;
        }
    }

    c = n / b;

    if (a != b && b != c && c > 1){
        cout << "YES" << endl;
        cout << a << " " << b << " " << c << " " << endl;
        return ;
    }

    cout << "NO" << endl;
    return ;

}

//**************************************************************************************************************************

int main(){
    solve();
    return 0;
}



