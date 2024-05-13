// https://www.codingninjas.com/codestudio/problems/redundant-brackets_975473?leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbarcodestudio&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio

#include <bits/stdc++.h>
#define pb push_back
#define ppb pop_back
using namespace std; 
#define inputVector(v, n)  for(auto i=0; i<n; i++) {int temp;    cin >> temp;    v.pb(temp);} 
#define print(K)    for(auto i : K) {cout << i << " ";}  cout << endl; 

#include <bits/stdc++.h> 
bool findRedundantBrackets(string &s){

    stack<char> stack;

    bool check = true;

    for(int i=0 ; i<s.size() ; i++){
        if(s[i]=='(' || s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/')
            stack.push(s[i]);

        else{

            if(s[i]==')'){
                int count = 0;
                while(stack.top() != '('){
                    stack.pop();
                    count++;
                }
                stack.pop();

                if(count == 0){
                    check = false;
                }
            }
        }
    }

    if(!check)   return 1;
    return 0;
}

int main(){

    string s = "((a+c*b)+(c))";   // Yes

    string s2 = "(a*b+(c/d))";   // No

    cout << "For " << s << " --> " << findRedundantBrackets(s) << endl;
    cout << "For " << s2 << " --> " << findRedundantBrackets(s2) << endl;
    
    return 0;
}

