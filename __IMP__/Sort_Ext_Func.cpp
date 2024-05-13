#include <bits/stdc++.h>
using namespace std;

// Sorting wrt dec order of frequency, and inc order of elements
bool cmp(int a, int b, map<int, int> &freq){
    if(freq[a] == freq[b]){
        return a < b; // Use a < b for ascending order
    }
    else{
        return freq[b] < freq[a];
    }
}

int main(){

    vector<int> v = {1, 2, 3, 4, 5, 2, 3, 4, 5, 5, 5};

    map<int, int> freq;
    for(auto i : v){
        freq[i]++;
    }

    // Sorting with external function
    sort(v.begin(), v.end(), [&](int a, int b) {
        return cmp(a, b, freq);
    });
    // sort(v.begin(), v.end(), [&](int a, int b) {
    //     return freq[a] == freq[b] ? a < b : freq[a] < freq[b];
    // });

    for(auto i : v){
        cout << i << " ";
    }

    // Answer = [5 5 5 5 2 2 3 3 4 4 1] 

}

