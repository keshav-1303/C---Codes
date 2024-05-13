#include <iterator>
#include <string>
#include <cstring>
#include <array>
#include <bits/stdc++.h>
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define inputArr(arr, n)   for( auto i = 0 ; i < n ; i++ )     cin >> arr[i];  
#define print(K)  for(auto i : K) {cout << i << " ";}  cout << endl; 
using namespace std;

int main(){

    // construction uses aggregate initialization
    // double-braces required
    array<int, 5> arr1 {3, 4, 5, 1, 2};
    array<int, 5> arr2 = {1, 2, 3, 4, 5};
    array<string, 3> arr3 = {"a","b","c"};

    sort(arr1.begin(), arr1.end());

    cout << "\nSorted ar1 : ";
    print(arr1);    cout << "and it's size is " << arr1.size() << endl;

    // Filling ar2 with 10
    arr2.fill(10);

    cout << "\nFilled arr2 : ";
    print(arr2);    cout << "and it's size is " << arr2.size() << endl;

    // ranged for loop is supported
    cout << "\narr3 : ";
    print(arr3);    cout << "and it's size is " << arr3.size() << endl;

    arr1.swap(arr2);     // Now arr1 and arr2 are swapped...      
    cout << "\nAfter swapping...\n";
    cout << "arr1 : ";
    print(arr1);
    cout << "arr2 : ";
    print(arr2);

    cout << "\nIs arr1 empty? -> " << arr1.empty() << endl << endl;                 // false ( not empty)

    const char *str = "GeeksforGeeks";
    array<char, 13> arr;
    memcpy(arr.data(), str, 13);    //used to copy data to arr.data() from str and 13 characters are copied
    print(arr);
    cout << str;

    return 0;
}
