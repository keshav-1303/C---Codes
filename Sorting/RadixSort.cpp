#include <bits/stdc++.h>
using namespace std;
#define print(K)    for(auto i : K) {cout << i << " ";}  cout << endl; 

void countSort(vector<int> &arr, int place){
    int maxi = 0, n = arr.size();
    for(auto i : arr){
        maxi = max(maxi, i);
    }

    vector<int> freq(10, 0);
    for(int i=0 ; i<n ; i++){
        freq[(arr[i]/place)%10]++;
    }

    for(int i=1 ; i<10 ; i++){
        freq[i] += freq[i-1];
    }

    vector<int> ans(n, 0);
	for (int i=n-1 ; i>=0 ; i--) {
		ans[freq[(arr[i]/place)%10]-1] = arr[i];
		freq[(arr[i]/place)%10]--;
	}

    for(int i=0 ; i<n ; i++){
        arr[i] = ans[i];
    }
}

void radixSort(vector<int> &arr){
    int maxi = 0;
    for(auto i : arr){
        maxi = max(maxi, i);
    }

    for(int i=1 ; maxi/i>0 ; i*=10){
        countSort(arr, i);
    }
}

int main(){
    vector<int> arr = {3, 4, 408, 654, 32};
    cout << "Original..." << endl;
    print(arr);

    radixSort(arr);
    cout << "Sorted..." << endl;
    print(arr);
}