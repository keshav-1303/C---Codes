#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

void print(vector<int> v){
    for(int i=0; i<v.size(); i++)    cout << v[i] << " ";
    cout << endl;
}

int main(){

    // no need to know copy()... instead use copy_n()
	
    vector <int> v = {1, 2, 3, 4, 5, 6, 7, 8, 6, 5, 3, 3, 3, 9, 0, 10};
    int size = v.size(); 

    vector <int> v1(size);

    copy_n(v.begin(), size, v1.begin());

    print(v1); 

	return 0;
}