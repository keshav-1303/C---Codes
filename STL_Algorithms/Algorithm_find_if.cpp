#include <bits/stdc++.h>
using namespace std;
 
bool IsOdd(int i){
    return i % 2;
}
 
int main(){

    vector<int> vec { 10, 25, 40, 55 };
 
    vector<int>::iterator it;
 
    //find_if
    it = find_if(vec.begin(), vec.end(), IsOdd);
    cout << "The first odd value is " << *it << '\n';
 
    vector<int>::iterator i;
 
    //find_if_not
    i = find_if_not(vec.begin(), vec.end(), IsOdd);
    cout << "The first even value is " << *i << '\n';
 
    return 0;
}