#include <algorithm>
#include <bits/stdc++.h>
#define print(K)  for(auto i : K) {cout << i << " ";}  cout << endl; 
using namespace std;
 
int main(){

    vector<int> vect = { 5, 10, 15, 20, 20, 23, 42, 45, 45, 45 };
 
    cout << "Given Vector is:\n";
    print(vect);
 
    // arr.erase(position to be deleted) – This erases selected element in vector and shifts and resizes the vector elements accordingly.
    vect.erase( find(vect.begin(),vect.end(),10) );
    cout << "\nVector after erasing element:\n";
    print(vect);

    // arr.erase(unique(arr.begin(),arr.end()),arr.end()) – This erases the duplicate occurrences in sorted vector in a single line.
    vect.erase(  unique(vect.begin(), vect.end())  ,  vect.end()  );
    cout << "\nVector after removing duplicates:\n";
    print(vect);
 
    return 0;
}