#include <bits/stdc++.h>
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
using namespace std;
#define inputArr(arr, n)   for( auto i = 0 ; i < n ;  i++ )     cin >> arr[i]; 
#define inputVector(v, n)  for(auto i=0; i<n; i++) {int temp;    cin >> temp;    v.pb(temp);} 
#define print(K)    for(auto i : K) {cout << i << " ";}  cout << endl; 
#define printmap(m)    for(auto i : m){ cout << i.first << " : " << i.second << endl; }

// https://www.codingninjas.com/codestudio/problems/valid-parenthesis_795104?topList=love-babbar-dsa-sheet-problems&leftPanelTab=1&campaign=Lovebabbarcodestudio&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio

bool isValidParenthesis(string str){

    stack<char> s;

    for (int i = 0; i < str.size(); i++){

        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
            s.push(str[i]);

        if (!s.empty()){

            if (str[i] == '}' && s.top() != '{')    return 0;
            else if (str[i] == '}' && s.top() == '{')
                s.pop();

            if (str[i] == ')' && s.top() != '(')    return 0;
            else if (str[i] == ')' && s.top() == '(')
                s.pop();

            if (str[i] == ']' && s.top() != '[')    return 0;
            else if (str[i] == ']' && s.top() == '[')
                s.pop();
            
        }

        else    return 0;
    }
    if(s.empty())    return 1;
    return 0;
}

int main(){

    string s;    cout << "Enter string : ";     cin >> s;

    cout << "Is Parenthesis VALID? -> " << isValidParenthesis(s) << endl;
    
    return 0;
}

