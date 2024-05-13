#include <bits/stdc++.h>
using namespace std;
#define sort_(a)    sort(a.begin(), a.end());
#define sort_rev(a)    {  sort(a.begin(), a.end());    reverse(a.begin(), a.end());  }
#define print(K)    {for(auto i : K)     cout << i << " ";}     cout << endl; 

int main(){

    int key = 9;
    vector<int> v = { 21, 9, 8, 7, 6, 4 };
    print(v);

    // Element just less than key
    sort_rev(v);    // Array must be in increasing order
    auto it = upper_bound(begin(v), end(v), key,  greater<int>());
    if (it != end(v))   cout << *it << endl;

    // Element less than equal to key
    sort_rev(v);    // Array must be in descending order
    it = lower_bound(begin(v), end(v), key,  greater<int>());
    if (it != end(v))   cout << *it << endl;

    // Element greater than key
    sort_(v);    // Array must be in ascending order
    it = upper_bound(begin(v), end(v), key);
    if (it != end(v))   cout << *it << endl;

    // Element greater than equal to key
    sort_(v);    // Array must be in ascending order
    it = lower_bound(begin(v), end(v), key);
    if (it != end(v))   cout << *it << endl;

}