#include <bits/stdc++.h>
using namespace std;

void print(vector<int> v){
    for(int i=0; i<v.size(); i++)    cout << v[i] << " ";
    cout << endl;
}
 
int main(){

    // No need to use fill(), instead use fill_n()

    vector<int> v1(10);

    fill_n(v1.begin(), v1.size(), 5);
    cout << "Vector v1 contains...\n";    print(v1);

    fill_n(v1.begin(), v1.size() - 3, 3);
    cout << "\nNow v1 contains...\n";   print(v1);
 
}