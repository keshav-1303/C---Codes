#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

void print(vector<int> v){
    for(int i=0; i<v.size(); i++)    cout << v[i] << " ";
    cout << endl;
}

int main(){
	
    vector <int> v = {1, 2, 3, 9, 0, 10, 4, 5, 6, 7, 8, 6, 5, 3, 3, 3, 9, 0, 10};
    int size = sizeof(v)/sizeof(v[0]); 

    vector<int> v1 = {9, 0, 10};
    vector<int> v2 = {0};   // can be used to find last occurence of 0

    cout << "\nfind" << endl;

    vector<int>::iterator it; 

    it = find_end(v.begin(), v.end(), v1.begin(), v1.end());    //returns last occurence of v1;
    cout << "Last occurence of v1 : " << it - v.begin() << endl;

    return 0;
}