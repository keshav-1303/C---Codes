#include <bits/stdc++.h>
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
using namespace std;
#define inputArr(arr, n)   for( auto i = 0 ; i < n ;  i++ )     cin >> arr[i]; 
#define inputVector(v, n)  for(auto i=0; i<n; i++) {int temp;    cin >> temp;    v.pb(temp);} 
#define print(K)    for(auto i : K) {cout << i << " ";}  cout << endl; 
#define printmap(m)    for(auto i : m){ cout << i.first << " : " << i.second << endl; }

vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c) {
    
    vector<int> ans;
    
    int startRow = 0;
    int endRow = r-1;
    int startCol = 0;
    int endCol = c-1;

    int count = r*c;

    int mid = matrix[r/2][c/2];
    
    while((startRow <= endRow && startCol <= endCol) && count > 0){
        
        int row = startRow;
        int col = startCol;
        
        while(col < endCol && count > 0){
            ans.pb(matrix[row][col]);
            count--; 
            col++;               
        }
        
        while(row < endRow && count > 0){
            ans.pb(matrix[row][col]);
            count--;
            row++;
        }
        
        while(col > startCol && count > 0){
            ans.pb(matrix[row][col]);
            count--;
            col--;
        }
        
        while(row > startRow && count > 0){
            ans.pb(matrix[row][col]);
            count--;
            row--;
        }
    
        startRow++;
        endRow--;
        startCol++;
        endCol--;
    }

    // if r and c are odd and equal then midmost element of matrix is always left
    // thus below step is must !!!

    if((r & 1 && c & 1) && r == c){
        ans.pb(mid);
    }
    
    return ans;
}

int main(){

    /*
    For input -->
    1 2 3 4
    5 6 7 8
    9 10 11 12
    ans must be --> 1 2 3 4 8 12 11 10 9 5 6 7
    */

    /*
    For input -->
    6 6 2 28 2 
    12 26 3 28 7 
    22 25 3 4 23
    ans must be --> 1 2 3 4 8 12 11 16 6 2 28 2 7 23 4 3 25 22 12 26 3 28
    */

    /*
    For input -->
    4 4 6 
    30 20 9 
    12 19 3
    ans must be --> 4 4 6 9 3 19 12 30 20
    */

    int row, col;
    cout << "Enter rows : ";    cin >> row;
    cout << "Enter columns : ";    cin >> col;

    cout << "Enter matrix -->" << endl;

    vector<vector<int>> matrix;

    for(int i=0 ; i<row ; i++){
        vector<int> temp;
        for(int j=0 ; j<col ; j++){
            int c;    cin >> c;
            temp.pb(c);
        }
        matrix.pb(temp);
    }

    vector<int> ans = spirallyTraverse(matrix, row, col);

    cout << endl;

    print(ans);
}