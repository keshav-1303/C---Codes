#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void input(ll **arr, ll row, ll col){
    for(ll i=0; i<row; i++){
        for(ll j=0; j<col; j++)    cin >> arr[i][j];
    }
}

void print(ll **arr, ll row, ll col){
    for(ll i=0; i<row; i++){
        for(ll j=0; j<col; j++)    cout << arr[i][j] << " ";
        cout << endl;
    }
}

int main(){

    ll row = 3, col = 3;
 
    ll** arr = (ll**)malloc(row * sizeof(ll*));

    for(ll i=0; i<row; i++){
        arr[i] = (ll*)malloc(col * sizeof(ll));
    }
 
    cout << "\nEnter Array elements : \n";    input(arr, row, col);
 
    cout << "\nEntered Array is : \n";    print(arr, row, col);
 
    free(arr);
 
    return 0;
}
