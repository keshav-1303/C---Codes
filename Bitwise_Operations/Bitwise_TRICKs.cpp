#include <bits/stdc++.h>
using namespace std;

int main(){

    // To check if number is ODD
    if(x & 1) == if(x is odd)
    if(!(x & 1)) == if(x is even)

    // To check if number is power of 2,    NOTE --> NOT APPLICABLE FOR X = 0
    if(x & (x-1) == 0) == if(x is power of 2)
    if(x & (x-1) > 0) == if(x is not a power of 2)
 
    // Playing with k-th bit
    if(x & (1LL << k)) == To check if k-th bit is set OR not (i.e 1 OR 0)
    x = (x ^ (1LL << k)) == To TOGGLE the k-th bit (i.e change 1 to 0 and vice-versa)
    x = (x || (1LL << k)) == To SET the k-th bit (i.e change 0 to 1)
    x = (x & ~(1LL << k)) == To UNSET the k-th bit (i.e change 1 to 0)

    // Multiply and divide by power(2, k)
    Multiplication --> (x << k) i.e. left shift by k
    Division --> (x >> k) i.e. right shift by k

    // Swap 2 numbers without using temporary variable (for x and y)
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;

    // PROPERTY
    if number of set bits in A = x; 
    if number of set bits in B = y; 
    if number of set bits in (A ^ B) = z;

    then, z is even if (x + y) is even
    then, z is odd if (x + y) is odd

    // TRICK
    if(x == a)    x = b;
    else if(x == b)    x = a;          // This can be done by x = (a ^ b ^ x);

    // PROPERTY
    a + b = (a ^ b) + 2*(a && b);
    a + b = (a || b) + (a && b);

    // Finding Number of SET BITS in a number x "IN O(1) COMPLEXITY"
    No of SET BITs = __builtin_popcount(x);    /// if x is an integer
    No of SET BITs = __builtin_popcountll(x);    /// if x is a long long integer
    
    // n | n-1 is n itself n ^ n-1 is 1

    return 0;
}

