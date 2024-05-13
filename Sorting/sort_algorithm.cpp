#include <bits/stdc++.h>
using namespace std;
#define print(K)    for(auto i : K) {cout << i << " ";}  cout << endl; 

// Time Complexity : O(N*logN)

int findN(int n){       // returns power of 2 on factorisation.
	int count = 0;
	while(!(n & 1)){

		if(n == 0)	 break;

		n = n >> 1;
		count++;
	}
	return count;
}

bool res(int a, int b){
    return (findN(a) > findN(b)) ? 1 : 0 ;
}

int main(){
	
    int arr[] = { 1, 4, 5, 2, 7, 2, 7, 5, 3, 9, 3, 9, 2 };
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "\nOriginal Array...\n";    print(arr);

    sort(arr, arr + n);
    cout << "\nIn Ascending order...\n";    print(arr);

    sort(arr, arr + n, greater<int>());
    cout << "\nIn Descending order...\n";    print(arr);

    //*************************************************************************

    vector<int> v = { 2, 5, 8, 10, 16, 1 };

    cout << "\nUsing user defined function...\n";
    sort(v.begin(), v.end(), res);    // function passed must return bool value.
    print(v);     cout << endl;

    return 0;
}