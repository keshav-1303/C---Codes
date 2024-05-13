#include <iostream>
using namespace std;

int gcd(int a, int b){	  

	while( a != 0  &&  b != 0 ){
		if(a > b)	   a = a-b;
		else	b = b-a;
	}

	if(a == 0)	return b;
	else	return a;
}

int main(){    // 1st get GCD then use -->  GCD(a,b) * LCM(a,b) = a * b

	int a;	 cout << "Enter a :";	   cin >> a;
	int b;	 cout << "Enter b :";	   cin >> b;

	cout << "LCM of " << a << " and " << b << " is " << (a*b)/gcd(a,b) << endl;
}
