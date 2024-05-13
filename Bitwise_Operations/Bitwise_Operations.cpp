#include <bits/stdc++.h>
using namespace std;

// The & (bitwise AND) 
// The | (bitwise OR) 
// The ^ (bitwise XOR) Odd One's detector 
// The << (left shift) in takes two numbers, left shifts the bits of the first operand, the second operand decides the number of places to shift. 
// The >> (right shift) in takes two numbers, right shifts the bits of the first operand, the second operand decides the number of places to shift. 
// The ~ (bitwise NOT) in takes one number and inverts all bits of it. (also called 1's complement)

void binary(int n){
	if(n == 0)	 return ;
	binary(n/2);
	cout << n % 2;
}

int findOdd(int arr[], int n){
    int res = 0, i;
    for (i = 0; i < n; i++)
        res ^= arr[i];
    return res;
}

int main(){

	int a=7, b=5;

	// int a1=(a|b), a2=a&b, a3=a^b, a4=a<<b, a5=a>>b, a6=~a;
	
	cout << a << " in binary is ";
	binary(a);
	cout << endl;
	cout << b << " in binary is ";
	binary(b);
	cout << endl;

	cout << a << " OR " << b << " is " << (a | b) << endl;
	cout << a << " AND " << b << " is " << (a & b) << endl;
	cout << a << " XOR " << b << " is " << (a ^ b) << endl;
	cout << a << " left shift " << b << " is " << (a << b) << endl;
	cout << a << " right shift " << b << " is " << (a >> b) << endl;
	cout << a << "'s One's Complement is " << (~a) << endl;

	cout << endl;

	int arr[] = { 12, 12, 14, 90, 14, 14, 14 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The odd occurring element is  "<< findOdd(arr, n);
	
	return 0;
}

/*
 The bitwise OR of two numbers is just the sum of those two numbers if there is no carry involved, otherwise you just add their bitwise AND. Let’s say, we have a=5(101) and b=2(010), since there is no carry involved, their sum is just a|b. Now, if we change ‘a’ to 6 which is 110 in binary, their sum would change to a|b + a&b since there is a carry involved.

 The bitwise XOR operator is the most useful operator from a technical interview perspective. It is used in many problems. A simple example could be “Given a set of numbers where all elements occur an even number of times except one number, find the odd occurring number” This problem can be efficiently solved by just doing XOR to all numbers. 

 The left shift and right shift operators should not be used for negative numbers. If the second operand(which decides the number of shifts) is a negative number, it results in undefined behaviour in C. For example results of both 1 <<- 1 and 1 >> -1 is undefined. Also, if the number is shifted more than the size of the integer, the behaviour is undefined. For example, 1 << 33 is undefined if integers are stored using 32 bits. Another thing is, NO shift operation is performed if additive-expression(operand that decides no of shifts) is 0. See this for more details. 
Note: In C++, this behavior is well-defined.
*/