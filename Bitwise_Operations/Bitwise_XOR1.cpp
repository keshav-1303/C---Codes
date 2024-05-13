// https://www.geeksforgeeks.org/tag/xor/      Check This and
// https://www.geeksforgeeks.org/bitwise-operators-in-c-cpp/

// SWAP 2 numbers by using only bitwise XOR operator.

#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int a=2, b=8;

    a=a^b;
    b=a^b;
    a=a^b;

    cout << "a is now : " << a << endl;
    cout << "b is now : " << b << endl;
	return 0;
}


