#include <bits/stdc++.h>
using namespace std;

int main(){
	
    priority_queue <int> maxi;    //always stores in descending order sequence

    priority_queue <int, vector<int>, greater<int>> mini;    //always stores in ascending order sequence

    maxi.push(1);    // 1
    maxi.push(3);    // 3, 1
    maxi.push(2);    // 3, 2, 1
    maxi.push(0);    // 3, 2, 1, 0

    while(!maxi.empty()){
        cout << maxi.top() << " ";
        maxi.pop();
    }cout << endl;

    mini.push(1);    // 1
    mini.push(3);    // 1, 3
    mini.push(2);    // 1, 2, 3
    mini.push(2);    // 1, 2, 2, 3
    mini.push(0);    // 0, 1, 2, 2, 3

    int m=mini.size();

    while(!mini.empty()){
        cout << mini.top() << " ";
        mini.pop();
    }cout << endl;

    cout<<"Is mini empty?-->"<<mini.empty();

	return 0;
}