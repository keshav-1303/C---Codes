#include <map>
#include <iostream>
using namespace std;

// Find frequencies of all elements in an array using maps...

int main(){

    int arr[40] = {1, 2, 3, 4, 4, 5, 6, 7, 8, 8, 1, 2, 3, 4, 4, 5, 6, 7, 8, 8, 1, 2, 3, 4, 4, 5, 6, 7, 8, 8, 1, 2, 3, 4, 4, 5, 6, 7, 8, 8,};

    int n = sizeof(arr)/sizeof(arr[0]);

    map<int, int> map;

    for(int i=0 ; i<n ; i++){
        map[arr[i]]++;
    }

    for(auto i : map){
        cout << i.first << " " << i.second << endl;
    }
    cout << endl;

}