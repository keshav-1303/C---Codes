// Add two numbers without using any of Arithmetic operations.

#include <bits/stdc++.h>
using namespace std;
 
int Add(int x, int y){

    int sum = x^y;
    int carry = x&y;
    return sum + carry;
}
 
int main(){

    int a = 200, b = 400;

    cout << a << " + " << b << " = " << Add(a, b);
    
    return 0;
}