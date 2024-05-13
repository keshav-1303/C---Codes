#include <bits/stdc++.h>
using namespace std;
#define print(K)    for(auto i : K) {cout << i << " ";}  cout << endl; 
int findN(int);       // returns power of 2 on factorisation.
bool res(int, int);

int main(){
	
    int arr[] = { 1, 4, 5, 2, 7, 2, 7, 5, 3, 9, 3, 9, 2 };
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "\nOriginal Array...\n";    print(arr);

    sort(arr, arr + n);
    cout << "\nIn Ascending order...\n";    print(arr);

    sort(arr, arr + n, greater<int>());
    cout << "\nIn Descending order...\n";    print(arr);

    //Comparator Function ***************************************************************

    vector<int> v = { 2, 5, 8, 10, 16, 1 };

    cout << "\nAcc to power of 2...\n";
    sort(v.begin(), v.end(), res);    // function passed must return bool value.
    print(v);     cout << endl;

    //is_sorted()*************************************************************************

    cout << "Is v Sorted --> " << is_sorted(v.begin(), v.end(), res) << endl;

    //nth_element()***********************************************************************

    nth_element(v.begin(), v.begin() + 3, v.end());
    print(v);
    // 8 ke left me saare usse chhote honge & 8 ke right me saare usse bade honge

    return 0;
}

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