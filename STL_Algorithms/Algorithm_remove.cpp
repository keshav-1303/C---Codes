#include <algorithm>
#include <bits/stdc++.h>
#define print(K)  for(auto i : K) {cout << i << " ";}  cout << endl; 
using namespace std;
 
int main(){

    vector<int> vect = { 5, 10, 15, 45, 20, 23, 42, 45, 45, 45 };
 
    cout << "Given Vector is:\n";
    print(vect);

    // It removes all ooccurences of elements equal to 'k' (here, k = 45)
    // Vcetor need not be sorted.
    vect.erase(  remove(vect.begin(), vect.end(), 45)  ,  vect.end()  );
    cout << "\nVector after removing duplicates:\n";
    print(vect);
 
    return 0;
}