#include <bits/stdc++.h>
using namespace std;

bool IsPallindrome(string str, int i){

    if(i == str.size()/2)   return true;

    if(str[i] != str[str.size()-i-1])   return false;

    i++;

    return IsPallindrome(str, i);
}

int main(){
	
    string str = "abcba";
    string s = "Keshav";

    cout << "Is Str Pallindrome--> " << IsPallindrome(str, 0) <<endl;
    cout << "Is Str Pallindrome--> " << IsPallindrome(s, 0) <<endl;

	return 0;
}