#include <bits/stdc++.h>
#include <set>
using namespace std;

int main(){
	
    // Set DO NOT store repeating values. It stores in sorted order & its values cannot be modified

    set <int> s;

    s.insert(0); 
    s.insert(1); 
    s.insert(1); 
    s.insert(1); 
    s.insert(2); 
    s.insert(2); 
    s.insert(3); 
    s.insert(0); 
    s.insert(4); 
    s.insert(3); 

    for(int i : s)    cout << i << " ";
    cout<<endl;

    set<int>::iterator it = s.begin();
    it++;
    it++;   // for accessing 2nd indexed element

    s.erase(it);

    for(int i : s)    cout<<i<<" ";
    cout<<endl;

    cout<<"4 present or not --> "<<s.count(4)<<endl;
    cout<<"2 present or not --> "<<s.count(2)<<endl;

	return 0;
}