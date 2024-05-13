#include <bits/stdc++.h>
using namespace std;

int compute(string str){

    int ans = 0;

    stack<int> s;
    int i = str.size() - 1;

    s.push((int)(str[i--] - '0'));
    while(i >= 0){

        while(str[i] >= '0' && str[i] <= '9'){
            s.push((int)(str[i--] - '0'));
        }

        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();

        if(str[i] == '+'){
            s.push(a+b);
        }
        else if(str[i] == '-'){
            s.push(a-b);
        }
        else if(str[i] == '*'){
            s.push(a*b);
        }
        else if(str[i] == '/'){
            s.push(a/b);
        }
        i--;
    }

    return s.top();
}

int main(){

    string s = "*+69-31";
    // "*+69-31" must give 30

    cout << compute(s) << endl;
 
    return 0;
}

