// lower_bound(first_iterator, last_iterator, x) – returns an iterator pointing to the first element in the range [first,last) which has a value not less than ‘x’.

#include <bits/stdc++.h>
#define print(K)  for(auto i : K) {cout << i << " ";}  cout << endl; 
using namespace std;

int main(){
    
    vector<int> v = { 8, 4, 5, 7, 2, 3, 4, 5 };

    sort(v.begin(), v.end());   //MUST

    cout << "Now vector becomes ...\n";
    print(v);

    vector<int>::iterator it = lower_bound(v.begin(), v.end(), 5);
    cout << "Lower bound of 5 : " << *it << endl;
    cout << "Lower bound index : " << it - v.begin() << endl;

    // deque<int> d = { 8, 4, 5, 7, 3, 3, 4, 5 };
    // deque<int>::iterator i = lower_bound(d.begin(), d.end(), 5);
    // cout << "Lower bound of 5 : " << *i << endl;

	return 0;
}