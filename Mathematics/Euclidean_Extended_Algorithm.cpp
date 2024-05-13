#include <iostream>
using namespace std;

int gcdExtended(int a, int b, int *x, int *y){	 
    // using gcd(a, b) = gcd(b, a % b);  and if any of a becomes zero return other.

	if(b == 0){
        *x = 1;   // because ax + by = gcd(a, b)  and b is 0 here
        *y = 0;   // therefore gcd will return a , ans equation becomes ax + 0 = a.
        return a;
    }

    int x1, y1;
    int g =  gcdExtended(b, a % b, &x1, &y1);

    *x = y1;
    *y = x1 - (a/b)*y1;

    return g;
}

int main(){	  

	int a = 35, b = 15;	 

    //find x,y such that ax + by = gcd(a, b)

    int x, y;

    if(a < b){
        a = a + b;
        b = a - b;
        a = a - b;
    }

	cout << "GCD of " << a << " and " << b << " is " << gcdExtended( a, b, &x, &y) << endl;
    cout << "x = " << x << " and b = " << y << " satisfies the equation." << endl;  
}
