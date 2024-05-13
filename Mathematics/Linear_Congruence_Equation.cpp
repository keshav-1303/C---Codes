// (A * x) % N = B    , x is the answer.

#include <bits/stdc++.h>
using namespace std;

// A solution exists if and only if B is divisible by GCD(A, N).
// The number of solutions for X is GCD(A, N).

int gcd(int a, int b){
    if(a < b)   swap(a, b);
    if(b == 0)   return a;
    return gcd(b, a % b);
}

int main(){
    
    int A = 15, B = 9, N = 8;

    int g = gcd(A, B);

    cout << "Number of solutions are : " << g << endl;

    if(B % g != 0)    cout << "No Solution exists !!!" << endl;

    else{
        
    }

	return 0;
}