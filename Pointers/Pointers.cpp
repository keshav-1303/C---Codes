#include <bits/stdc++.h>
using namespace std;



int main(){
	
    // int num = 5;
    // char ch = 'c';

    // int *p = 0;
    // char *ptr = &ch;

    // num++;

    // cout << sizeof(num) << endl; 
    // cout << sizeof(p) << endl;

    // cout << sizeof(ch) << endl;
    // cout << sizeof(ptr) << endl;
    // // cout << *p++ << endl;

    // int n = 45;
    // int* p = &n;
    // int** ptr = &p;

    // cout << "n = " << n << endl;
    // cout << "n = " << *p << endl;
    // cout << "Address of n = " << &n << endl;
    // cout << "Address of p = " << p << endl;
    // cout << "Value at n = " << *(*ptr) << endl;
    // cout << "p's address = " << ptr << endl;

    //TRICKY QUESTIONs....

    char arr[] = "abcde";   
    char* p = &arr[0];
    p++;

    cout << p << endl;      // Answer = ?
    
	return 0;
}