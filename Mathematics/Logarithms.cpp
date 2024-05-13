#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;    cout << "Enter n : ";     cin >> n;

    cout << log(n) << endl;
    cout << log10(n) << endl;

    cout << "isdigit(log(n)) --> " << isdigit(log(n)) << endl;
    cout << "isdigit(log10(n)) --> " << isdigit(log10(n)) << endl;
    cout << "isdigit('2') --> " << isdigit('2') << endl;
    
    return 0;
}

