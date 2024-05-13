// X is the modulo inverse of A under M , it satisfies (A * X) % M = 1  (where 1 <= X <= M-1).

// The multiplicative inverse of “A modulo M” exists if and only if A and M are relatively prime (i.e. if gcd(A, M) = 1)

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll Modular_Inverse(ll p,ll q){
    
    ll exponent , MOD = 1e9+7;
    exponent = MOD - 2;
    while(exponent) {
 
        if (exponent & 1) {
            p = (p * q) % MOD;
        }
        q = (q * q) % MOD;
        exponent >>= 1;
    }
    return p;
}

int gcdApproach(int a, int b, int *x, int *y){  // solve Ax + My = 1 , +ve one will be the answer.
                                                // Time Complexity : O(log M)
    if(a < b)   swap(a, b);

    if(b == 0){
        *x = 1;
        *y = 0;
        return a;
    }

    int x1, y1;
    int gcd = gcdApproach(b, a % b, &x1, &y1);

    *x = y1;
    *y = x1 - (a/b)*y1;

    return gcd;
}

int main(){
    
    //A naive method is to try all numbers from 1 to m. For every number x, check if (A * X) % M is 1
    
    int A = 3, M = 11;    //find X = ?

    int x, y;
    int gcd = gcdApproach(A, M, &x, &y);

    cout << "Modulo inverse of " << A << " under " << M << " is " << Modular_Inverse(A, M) << endl;

    int ans;
    if(x < 0)   ans = y;
    else    ans = x;

    cout << "Modulo inverse of " << A << " under " << M << " is " << ans << endl;

	return 0;
}



