#include <bits/stdc++.h>
#include <deque>
using namespace std;

int main(){
	
	deque <int> a ;

	a.push_back(1);		//push_front() is not available in vector, it is in deque

	a.push_back(2);

	a.push_back(3);

	a.push_front(3);

	cout<<"Front : "<<a.front()<<endl;
	cout<<"Back : "<<a.back()<<endl;

	cout<<"Before pop..."<<endl;

	for(int i=0; i<a.size(); i++)	   cout<<a[i]<<" ";
	cout<<endl;

	cout<<"After pop..."<<endl;

	a.pop_back();
	a.pop_front();

	for(int i:a)	   cout<<i<<" ";
	cout<<endl;
	
	cout<<"Before clear..."<<a.size()<<endl; 

	a.clear();

	cout<<"After clear..."<<a.size()<<endl;

	return 0;
}