#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

void print(vector<int> v){
    for(int i=0; i<v.size(); i++)    cout << v[i] << " ";
    cout << endl;
}

int main(){ // Wrong output!!!!!!!
	
    vector <int> v = {1,2,3,4,5,6,7,8,6,5,3,3,3,9,0,11,10};
    int size = sizeof(v)/sizeof(v[0]);  

    vector<int>::iterator i = v.begin()+7;

    cout << "Target element is : " << *i << endl;

    nth_element(v.begin(), i, v.end());

    print(v);

	return 0;
}