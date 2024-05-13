// C++ program to find out execution time of functions
#include <algorithm>
#include <chrono>
#include <iostream>
#include<vector>
using namespace std;
using namespace std::chrono;

int gcd(int a, int b){	  // using gcd(a,b)=gcd(a-b,b);	   and if any of a,b becomes zero return other.

	while( a != 0  &&  b != 0 ){
		if(a > b)	   a = a-b;
		else	b = b-a;
	}

	if(a == 0)	return b;
	else	return a;
}

// int gcd(int a, int b){
//     if(b == 0)     return a;
//     else    return gcd(b, a % b);
// }
 
int main(){
 
    int a=10000000, b=23;

    // cout << "Enter a : ";    cin >> a;
    // cout << "Enter b : ";    cin >> b;

    auto start = high_resolution_clock::now();    // Get starting timepoint

    // Call the function, here sort()

    int c = gcd(a, b);

 
    auto stop = high_resolution_clock::now();    // Get ending timepoint
 
    // Get duration. Substart timepoints to get duration. To cast it to proper unit use duration cast method
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "GCD is " << c << endl;
 
    cout << "Time taken by function is " << duration.count() << " microseconds" << endl;
 
    return 0;
}