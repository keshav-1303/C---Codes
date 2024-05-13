#include <bits/stdc++.h>
using namespace std;
#define print(K)    for(auto i : K) {cout << i << " ";}  cout << endl; 

bool find3Numbers(int A[], int n, int X){
        
    sort(A, A + n);

    for(int i=0 ; i<n ; i++)     cout << A[i] << " ";
    cout << endl;

    int i = 0 , j , k;

    int midi = (i1 + i2)/2;

    while(i2 < i1 > 1){

        int midi = (i1 + i2)/2;

        int j1 = i1+1 , j2 = i2-1;
        
    }
    
    return 0;
}

// bool find3Numbers(int A[], int n, int X){
        
//     int i = 0 , j = n-1 , count = 0;
    
//     while(j - i > 1){
        
//         int sum = A[i] + A[j];
        
//         for(int ind = i+1 ; ind < j ; ind++){
//             sum = sum + A[ind];

//             cout << A[i] << "+" << A[ind] << "+" << A[j] << "=" << A[i] + A[ind] + A[j] << endl;
            
//             if(sum == X)    return 1;
//             sum = sum - A[ind];
//         }
        
//         if(count & 1)    i++;
//         else    j--;
        
//         count++;
//     }
    
//     return 0;
// }

int main(){

    int A[] = { 174, 430, 405, 706, 627, 813, 376, 94, 566, 37, 737, 142, 815, 995, 257, 653, 937, 839, 483, 356, 16, 132, 231, 842, 626, 12, 638};

    int size = sizeof(A)/sizeof(A[0]);

    int X = 1107;

    cout << find3Numbers(A, size, X) << endl;

}