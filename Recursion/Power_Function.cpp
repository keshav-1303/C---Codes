#include <bits/stdc++.h>
using namespace std;

int power(int a, int b){

    if(b/2 == 0)    return a;

    if(b%2 == 0)    return power(a, b/2)*power(a, b/2);

    else    return power(a, b/2)*power(a, b/2)*a;
}

int main(){
	
    int a, b;

    cout << "Enter a : ";    cin >> a;
    cout << "Enter b : ";    cin >> b;

    cout << "power(a, b) = " << power(a ,b) << endl;
	return 0;
}