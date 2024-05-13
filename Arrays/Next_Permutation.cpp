// https://www.codingninjas.com/studio/problems/next-greater-permutation_6929564?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

// Return the next permutaion of given array

#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

vector<int> nextGreaterPermutation(vector<int> &a) {
    
    // 1. Longer prefix match (find i from back s.t a[i] < a[i+1])
    // 2. For that i, find element from [i+1 ... n-1] which is just
    //    greater than a[i] (i. e smallest possible after a[i]) & SWAP it.
    // 3. Now we need as small as possible for i+1 ... n-1, So reverse that part.

    int n = a.size(), ind = -1;
    // STEP 1
    for(int i=n-2 ; i>=0 ; i--){
        if(a[i] < a[i+1]){
            ind = i;
            break;
        }
    }

    if(ind == -1){
        // it is the last permutation.
        reverse(a.begin(), a.end());
        return a;
    }

    // STEP 2
    for(int i=n-1 ; i>0 ; i--){
        if(a[i] > a[ind]){
            swap(a[i], a[ind]);
            break;
        }
    }

    // STEP 3
    reverse(a.begin()+ind+1, a.end());

    return a;

}