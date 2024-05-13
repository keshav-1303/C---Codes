#include <bits/stdc++.h>
using namespace std;

int main(){
    
    vector<int> v = { 8, 4, 5, 7, 2, 3, 4, 5 };
    vector<int>::iterator it = min_element(v.begin(), v.end());
    cout << "Smallest element in vector is : " << *it << endl;

    deque<int> d = { 8, 4, 5, 7, 3, 3, 4, 5 };
    deque<int>::iterator i = min_element(d.begin(), d.end());
    cout << "Smallest element in deque is : " << *i << endl;

	return 0;
}