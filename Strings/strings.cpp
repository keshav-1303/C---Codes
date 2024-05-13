#include <bits/stdc++.h>
using namespace std;

int main(){
	
    // Strings end with '\0'
    // Declaring and initialising...
    
    string s1="keshav";
    string s2="lohani";

    string s3;
    string s4 {"Frank"};      // Frank
    string s5 {s4};           // Frank 
    string s6 {"keshav",2,4}; // shav
    string s7 {s4,2,2};       // an
    string s8 {6,'X'};        // ♠X

    s1.push_back('k');

    reverse(s4.begin(), s4.end()-2);

    cout<<"\ns3 is "<<s3<<endl;
    cout<<"s4 is "<<s4<<endl;
    cout<<"s5 is "<<s5<<endl;
    cout<<"s6 is "<<s6<<endl;
    cout<<"s7 is "<<s7<<endl;
    cout<<"s8 is "<<s8<<endl;

    cout<<"\nLength of s1 is "<<s1.length()<<endl;
    string s=s1.append(s2);

    cout<<"s is "<<s<<endl;

    cout<<"s is "<<s[4]<<endl;

    string ss=s.substr(4,7);

    cout<<"ss is "<<ss<<endl;

    cout<<"1st occurence : "<<s.capacity();

    
	return 0;
}