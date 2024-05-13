#include <bits/stdc++.h>
using namespace std;

int main(){

    double x = 1.411, y = 1.500, z = 1.711;

    // Floor rounds off the given value to the closest integer which is less than the given value. 

    cout << "Floor --> " << endl;
	cout << floor(x) << endl;
	cout << floor(y) << endl;
	cout << floor(z) << endl;


    // Ceil rounds off the given value to the closest integer which is more than the given value. 

    cout << "Ceil --> " << endl;
    cout << ceil(x) << endl;
    cout << ceil(y) << endl;
    cout << ceil(z) << endl;


    // Trunc rounds remove digits after the decimal point

    cout << "Trunc --> " << endl;
    cout << trunc(x) << endl;
    cout << trunc(y) << endl;
    cout << trunc(z) << endl;

 
    // Rounds gave numbers to the closest integer

    cout << "Round --> " << endl;
    cout << round(x) << endl;
    cout << round(y) << endl;
    cout << round(z) << endl;


    // Setprecision when used along with "fixed" provides precision to floating-point numbers 
    // correct to decimal numbers mentioned in the brackets of the setprecision. 
    // It is defined in header file <iomanip>.

    cout << "setprecision() --> " << endl;
    double pi = 3.141592653589793238462643383279;
    cout << fixed << setprecision(0) << pi << endl;
    cout << fixed << setprecision(1) << pi << endl;
    cout << fixed << setprecision(2) << pi << endl;
    cout << fixed << setprecision(3) << pi << endl;
    cout << fixed << setprecision(4) << pi << endl;
    cout << fixed << setprecision(5) << pi << endl;
    cout << fixed << setprecision((numeric_limits<double>::digits10 + 1)) << pi << endl;

    // double n = setprecision(4) pi ;
    // cout << n << endl; 
    
    return 0;
}

