#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int arr[] = { 8, 11, 5, 7, 2, 3, 4, 5 };    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Sum of all elements : " << accumulate(arr, arr + n, 0) << endl;
    // 0 means sum = 0 then sum += v[i];

    vector<int> v = { 8, 11, 5, 7, 2, 3, 4, 5 };
    cout << "Sum of all elements : " << accumulate(v.begin(), v.end(), 10) << endl;
    // 10 means sum = 10 then sum += v[i];

    deque<int> d = { 8, 11, 5, 7, 2, 3, 4, 5 };
    cout << "Sum of all elements : " << accumulate(d.begin(), d.end(), 0) << endl;
    // 0 means sum = 0 then sum += d[i];

    set<int> s = { 8, 11, 5, 5, 2, 2, 4, 5 };
    cout << "Sum of all elements : " << accumulate(s.begin(), s.end(), 0) << endl;
    // 0 means sum = 0 then sum += s[i];

	return 0;
}