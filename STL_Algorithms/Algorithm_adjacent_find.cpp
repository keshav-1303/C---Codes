#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
int main(){
    
    vector<int> A = { 10, 13, 16, 16, 18, 18 };  // Sorted Array is must!!!
 
    int n = sizeof(A) / sizeof(A[0]);
 
    vector <int>::iterator it ;
    
    it = adjacent_find(A.begin(), A.end());;    //returns address of 1st reapeating element.

    // Printing the result
    cout << "Index : " << it - A.begin() << endl;     //Getting index
    cout << "Value : " << *it << endl;    //Getting value
}