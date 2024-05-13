#include <bits/stdc++.h>
using namespace std;

string Reverse(string s){   //using loop
    int i=0, j=s.size()-1;
    while(i<j)    swap(s[i++], s[j--]);
    return s;
}

void RevString(string &s, int i){    //passing by reference

    if(i == s.size()/2)    return ; 

    swap(s[i], s[s.size()-i-1]);
    i++;
    RevString(s, i);
}

string ReverseString(string s, int i){    //passing by value

    cout << "String is now " << s <<" ";

    if(i==s.size()/2){
        return s; 
    }

    swap(s[i], s[s.size()-i-1]);
    i++;
    ReverseString(s, i++);
}

int main(){
	
    string s = "Keshav";

    RevString(s, 0);
    // string rev = ReverseString(s, 0, s.size()-1);

    cout << "Reversed string is " << s << endl;
    // cout << "Reversed string is " << rev << endl;

	return 0;
}