#include <bits/stdc++.h>
#include <map>
using namespace std;

int main(){
	
    map <int,string> m;

    m[1]="Keshav";
    m[0]="asdf";
    m[5]="Lohani";
    m[2]="Abcd";

    m.insert({4,"bheem"});

    cout<<"Is 13 present?--> "<<m.count(13)<<endl;
    cout<<"Is 5 present?--> "<<m.count(5)<<endl;

    // for(int i=0; i<6; i++){
    //     cout<<m.first()<<" "<<m.second()<<endl;
    // }cout<<endl;

    map<int,string>::iterator it = m.begin();
 
    cout<<"Before erasing...\n";
    while (it != m.end()){
        cout << it->first << " : " << it->second <<endl;
        ++it;
    }

    m.erase(5);

    map<int,string>::iterator it1 = m.begin();

    cout<<"After erasing...\n";
    while (it1 != m.end()){
        cout << it1->first << " : " << it1->second <<endl;
        ++it1;
    }

    


	return 0;
}