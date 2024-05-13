#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

void print(vector<int> v){
    for(int i=0; i<v.size(); i++)    cout << v[i] << " ";
    cout << endl;
}

bool iseven(int i){
    if(i%2 == 0)    return true;
    else    return false;
}
bool isgreaterthan5(int i){
    if(i > 5)    return true;
    else    return false;
}

int main(){
	
    vector <int> v = {1,2,3,4,5,6,7,8,6,5,3,3,3,9,0,10};
    int size = sizeof(v)/sizeof(v[0]);  

    cout << "Elements even are : " << count_if(v.begin(), v.end(), iseven) << endl; 
    cout << "Elements > 5 are : " << count_if(v.begin(), v.end(), isgreaterthan5) << endl; 

	return 0;
}