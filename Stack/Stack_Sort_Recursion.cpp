#include <bits/stdc++.h> 
using namespace std;

// https://www.codingninjas.com/codestudio/problems/sort-a-stack_985275?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0?source=youtube&campaign=Lovebabbarcodestudio&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio

void insert(stack<int> &s, int x){

	if(s.empty()){
		s.push(x);
		return ;
	}

	if(s.top() >= x){     // for descending use if(s.top() <= x)
		s.push(x);
		return ;
	}

	int num = s.top();

	s.pop();

	insert(s, x);

	s.push(num);
}

void sortStack(stack<int> &s){

	if(s.empty()){
		return ;
	}

	int num = s.top();

	s.pop();

	sortStack(s);

	insert(s, num);
}

int main(){

    stack<int> s;
    s.push(3);
    s.push(4);
    s.push(1);
    s.push(3);
    s.push(4);
    s.push(6);
    s.push(2);
    s.push(9);

    cout << "Original Stack ...\n";
    stack<int> s1 = s;
    while(!s1.empty()){
        cout << s1.top() << " ";
        s1.pop();
    }

    sortStack(s);

    cout << "\nSorted Stack ...\n";
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
 
    return 0;
}
