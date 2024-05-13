#include <bits/stdc++.h> 
#define print(K)    for(auto i : K) {cout << i << " ";}  cout << endl; 
using namespace std;

// Time Complexity :  O(N + K) where N is the number of elements in the input array and K is the range of input. 

// Step 1 : Find count of every distinct element in array.
// Step 2 : Calculate position of each element in sorted array

void countsort(vector<int> &arr, int n){

    vector<int> freq(*max_element(arr.begin(), arr.end())+1, 0);
    for(auto i : arr){
        freq[i]++;
    }

    int j = 0;
    for(int i=0 ; i<freq.size() ; i++){
        while(freq[i] > 0){
            arr[j++] = i;
            freq[i]--;
        }
    }
}

int main(){
	
    vector<int> arr = {1,4,5,2,7,2,7,5,3,9,3,9,2};

    int size = sizeof(arr)/sizeof(arr[0]);

    print(arr);

    countsort(arr, size);
    
    print(arr);
    
	return 0;
}