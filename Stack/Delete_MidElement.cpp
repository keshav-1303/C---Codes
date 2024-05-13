#include<bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/codestudio/problems/delete-middle-element-from-stack_985246?leftPanelTab=1&campaign=Lovebabbarcodestudio&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio

void deleteMiddle(stack<int>&s, int N){
	
   int mid = N / 2 , count = 0;

   vector<int> v;
   
   while(count < mid){
      v.push_back(s.top());
      s.pop();
      count++;
   }

   s.pop();

   while(v.size() != 0){
      s.push(v.back());
      v.pop_back();
   }
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

    cout << "Before removing ...\n ";
    stack<int> s1 = s;
    for(int i=0 ; i<s.size() ; i++){
        cout << s1.top() << " ";
        s1.pop();
    }

    deleteMiddle(s, s.size());

    cout << "\nAfter removing ...\n ";

    stack<int> s2 = s;
    for(int i=0 ; i<s.size() ; i++){
        cout << s2.top() << " ";
        s2.pop();
    }
}
