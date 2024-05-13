#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

void print(vector<int> v){
    for(int i=0; i<v.size(); i++)    cout << v[i] << " ";
    cout << endl;
}

int main(){
	
    vector <int> v = {1,2,3,4,5,6,7,8,6,5,3,3,3,9,0,10};
    int size = sizeof(v)/sizeof(v[0]);
    sort(v.begin(), v.end());

    cout << "\nBinary Search" << endl;
    int key = 6;
    
    // cout << "Enter key for binary_search : ";    cin >> key;

    cout << "Is " << key << " present -> " << binary_search(v.begin(), v.end(), key)<<endl;    
    cout << "Is " << key+10 << " present -> " << binary_search(v.begin(), v.end(), key+10)<<endl;  

    return 0;
}