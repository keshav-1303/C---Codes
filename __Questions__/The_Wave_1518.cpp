// https://www.codechef.com/problems/WAV2
// Solve using Binary Search

#include <bits/stdc++.h>
using namespace std;

string Sign(long long int temp, long long int *arr, int n){
    string s = "";

    if (temp < arr[0])    s = "POSITIVE";

    else if (temp > arr[n - 1]){
        if (n % 2 == 0)    s = "POSITIVE";
        else    s = "NEGATIVE";
    }

    if (s == ""){
        
        for (int i = 0; i < n; i++){
            
            if (temp > arr[i] && temp < arr[i + 1]){
                if (i % 2 == 0)    s = "NEGATIVE";
                else    s = "POSITIVE";
                break;
            }

            if (temp == arr[i]){
                s = "0";
                break;
            }
        }
    }
    return s;
}

int main(){

    int n, q;
    cin >> n >> q;

    long long int arr[n];
    for (int i = 0; i < n; i++)    cin >> arr[i];

    sort(arr, arr + n);

    for (int i = 0; i < q; i++){
        
        long long int temp;   cin >> temp;

        cout << Sign(temp, arr, n) << endl;
    }

    return 0;
}