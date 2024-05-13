#include <bits/stdc++.h>
using namespace std;

int main(){

    string str = "keshav";

    stack<char> s;

    for(int i=0 ; i<str.size() ; i++)    s.push(str[i]);

    string ans = "";

    while(!s.empty()){
        ans = ans + s.top();
        s.pop();
    }

    cout << "Reversed string is " << ans << endl;

    return 0;
}

