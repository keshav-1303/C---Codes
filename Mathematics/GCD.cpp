#include <iostream>
using namespace std;

int gcd(int a, int b){	  // using gcd(a,b)=gcd(a-b,b);	   and if any of a,b becomes zero return other.

	while( a != 0  &&  b != 0 ){
		if(a > b)	   a = a-b;
		else	b = b-a;
	}

	if(a == 0)	return b;
	else	return a;
}

int main(){	  

	int a;	 cout << "Enter a :";	   cin >> a;
	int b;	 cout << "Enter b :";	   cin >> b;

	cout << "GCD of " << a << " and " << b << " is " << gcd(a,b) << endl;
}
