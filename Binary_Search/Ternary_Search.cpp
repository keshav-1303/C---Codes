#include <bits/stdc++.h>
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define inputArr(arr, n)   for( auto i = 0 ; i < n ; i++ )     cin >> arr[i]; 
#define inputVector(v, n)  for(auto i=0; i<n; i++) {int temp;    cin >> temp;    v.pb(temp);} 
#define inputDeque(d, n)   for(auto i=0; i<n; i++) {int temp;    cin >> temp;    d.pb(temp);} 
#define inputSet(s, n)   for(auto i=0; i<n; i++) {int temp;    cin >> temp;    s.insert(temp);} 
#define print(K)    for(auto i : K) {cout << i << " ";}  cout << endl; 
#define printmap(m)    for(auto i : m){ cout << i.first << " : " << i.second << endl; }
#define MOD 1000000007
#define PI 3.14159265359
#define ll long long int
using namespace std;

bool Ternary_Search(vector<int> &arr, int size, int key){

    int s = 0, e = size - 1;
    int mid1 = s + (e - s)/3;
    int mid2 = e - (e - s)/3;

    while(s <= e){

        if(arr[mid1] == key)    return 1;
        if(arr[mid2] == key)    return 1;

        if(key > arr[mid1]  &&  key < arr[mid2]){
            s = mid1 + 1;
            e = mid2 - 1;
        }

        else if(key < arr[mid1])    e = mid1 - 1;

        else    s = mid2 + 1;

        mid1 = s + (e - s)/3;
        mid2 = e - (e - s)/3;
    }
    return 0;
}

int main(){
    
    vector<int> arr = { 1, 2, 3, 3, 3, 3, 4, 5, 5, 5, 7, 8, 9, 9, 9, 11 };   
                            // Sorted Array is MUST!!
                            // Time Complexity : O(log n base 3) , similar to binary search but 3 partitions.

    int key = 4;

    cout << "Given vector is...\n";
    print(arr);

    int size = arr.size();

    cout << "Is " << key << " present --> " << Ternary_Search(arr, size, key) << endl;

    return 0;
}