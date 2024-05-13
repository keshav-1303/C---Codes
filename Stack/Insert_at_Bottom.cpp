// https://www.codingninjas.com/codestudio/problems/insert-an-element-at-its-bottom-in-a-given-stack_1171166?topList=love-babbar-dsa-sheet-problems&leftPanelTab=1&campaign=Lovebabbarcodestudio&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio

#include <bits/stdc++.h> 
using namespace std; 

stack<int> pushAtBottom(stack<int>& s, int x) 
{
    vector<int> v;

    while(!s.empty()){
        v.push_back(s.top());
        s.pop();
    }

    s.push(x);

    while(!v.empty()){
        s.push(v.back());
        v.pop_back();
    }

    return s;
}

int main(){

    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);

    int x;    cout << "Enter x : ";     cin >> x;

    cout << "Before pushing ...\n ";
    stack<int> s1 = s;
    for(int i=0 ; i<s.size() ; i++){
        cout << s1.top() << " ";
        s1.pop();
    }

    stack<int> s2 = pushAtBottom(s, x);

    cout << "\nAfter removing ...\n ";

    for(int i=0 ; i<s.size() ; i++){
        cout << s2.top() << " ";
        s2.pop();
    }
}
