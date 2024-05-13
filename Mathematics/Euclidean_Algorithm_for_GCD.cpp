#include <iostream>
using namespace std;

int gcd(int a, int b){	  // using gcd(a, b) = gcd(b, a % b);	   and if any of a becomes zero return other.

	if(b == 0)    return a;
    return gcd(b, a % b);
}

int main(){	  

	int a;	 cout << "Enter a : ";	   cin >> a;
	int b;	 cout << "Enter b : ";	   cin >> b;

    if(a < b)    swap(a, b);

    int gcd = gcdExtended( a, b, &x, &y);
    if(x > y)    swap(x, y);

	cout << "GCD of " << a << " and " << b << " is " << gcd << endl;
    cout << "x = " << x << " and y = " << y << " satisfies the equation." << endl; 
}
