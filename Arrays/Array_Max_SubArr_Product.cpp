#include <bits/stdc++.h>
using namespace std;

long long maxProduct(vector<int> arr, int n) {
	    
    long long product = 1;
    long long maxi = INT_MIN;
    
    for(int i=0 ; i<n ; i++){
        
        product = product * arr[i];
        maxi = max(maxi, product);
        
        if(product == 0)    product = 1;
    }
    
    product = 1;
    
    for(int i=n-1 ; i>=0 ; i--){
        
        product = product * arr[i];
        maxi = max(maxi, product);
        
        if(product == 0)    product = 1;
    }
    
    return maxi;
}

int main(){

    vector<int> v = {-8, 5, 3, 1, 6};

    cout << maxProduct(v, v.size());
 
    return 0;
}

