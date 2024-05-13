#include <bits/stdc++.h>
using namespace std; 
#define print(K)    for(auto i : K) {cout << i << " ";}  cout << endl; 

// https://practice.geeksforgeeks.org/problems/common-elements1132/1

vector<int> common(vector<int> &A, vector<int> &B){
            
    int i = 0 , j = 0;
    
    vector<int> ans;
            
    while(i < A.size() && j < B.size()){
        
        if(A[i] == B[j]){
            ans.push_back(A[i]);
            i++;
            j++;
        }
        
        while(A[i] < B[j] && i < A.size() && j < B.size())    i++;
        while(A[i] > B[j] && i < A.size() && j < B.size())    j++;

    }
    
    return ans;
}

vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3){
    
    vector<int> a(A, A + n1);
    vector<int> b(B, B + n2);
    vector<int> c(C, C + n3);
   
    vector<int> ans1 = common(a, b);
    
    vector<int> ans2 = common(b, c);
    
    vector<int> ans = common(ans1, ans2);
    
    return ans;
}

int main(){

    int A[] = {3, 3, 3};
    int B[] = {3, 3, 3};
    int C[] = {3, 3, 3};

    // ans must be {3};

    int n1 = sizeof(A)/sizeof(A[0]);
    int n2 = sizeof(B)/sizeof(B[0]);
    int n3 = sizeof(C)/sizeof(C[0]);

    vector<int> ans = commonElements(A, B, C, n1, n2, n3);

    set<int> s(ans.begin(), ans.end());
    vector<int> final(s.begin(), s.end());

    print(final);
    
    return 0;
}

