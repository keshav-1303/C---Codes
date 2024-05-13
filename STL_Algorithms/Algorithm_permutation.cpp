#include <algorithm>
#include <iostream>
#include <vector>
#define print(K)  for(auto i : K) {cout << i << " ";}  cout << endl; 
using namespace std;
 
int main(){
    
    vector<char> vect { 'a', 'b', 'a', 'a', 'c', 'd' };

    sort(vect.begin(), vect.end());
 
    cout << "Sorted Vector is:\n";
    print(vect);
 
    // modifies vector to its previous permutation order
    prev_permutation(vect.begin(), vect.end());
    cout << "\nVector after performing prev permutation:\n";
    print(vect);

    cout << "\nVector after performing 5 next permutations:\n";
    for(int i=0; i<5; i++){
        next_permutation(vect.begin(), vect.end());    // modifies vector to its next permutation order
        print(vect);
    }
 
    return 0;
}