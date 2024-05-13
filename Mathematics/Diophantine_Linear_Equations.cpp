// Given three integers a, b, and c representing a linear equation of the form: ax + by = c. The task is to find the initial integral solution of the given equation if a finite solution exists.

#include <iostream>
using namespace std;

int gcd(int a, int b, int *x, int *y){	 

	if(b == 0){
        *x = 1;   // because ax + by = gcd(a, b)  and b is 0 here
        *y = 0;   // therefore gcd will return a , ans equation becomes ax + 0 = a.
        return a;
    }

    int x1, y1;
    int g =  gcd(b, a % b, &x1, &y1);

    *x = y1;
    *y = x1 - (a/b)*y1;

    return g;
}

int main(){	  

//     Approach: 

// First, check if a and b are non-zero.
// If both of them are zero and c is non-zero then, no solution exists. If c is also zero then infinite solution exits.
// For given a and b, calculate the value of x1, y1, and gcd using Extended Euclidean Algorithm.
// Now, for a solution to existing gcd(a, b) should be multiple of c.
// Calculate the solution of the equation

	int a = 4, b = 18, c = 10;

    //find x,y such that ax + by = c

    int x, y;

    if(a < b)    swap(a, b);

    int g = gcd( a, b, &x, &y);

    if(x > y)    swap(x, y); 

    int k = c / g;
    x = k*x;
    y = k*y;

    cout << "Solution to equation " << a << "x + " << b << "y = " << c << " is x = " << x << " , y = " << y << endl;
}
