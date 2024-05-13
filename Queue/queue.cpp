#include <bits/stdc++.h>
#include <queue>
using namespace std;

int main(){
	
    queue <string> q;   // First IN First OUT

    q.push("Keshav");
    q.push("Lohani");
    q.push("Abcd");

    cout<<"1st element is "<<q.front()<<" and size is "<<q.size()<<endl;

    q.pop();

    cout<<"1st element is "<<q.front()<<" and size is "<<q.size()<<endl;

    cout<<"is s Empty?... "<<q.empty()<<endl;

	return 0;
}