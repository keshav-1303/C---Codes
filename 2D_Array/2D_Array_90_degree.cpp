#include <bits/stdc++.h>
using namespace std;

void input(int **arr, int row, int col){
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++)    cin >> arr[i][j];
    }
}

void print(int **arr, int row, int col){
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++)    cout << arr[i][j] << " ";
        cout << endl;
    }
}

void rotateMatrix(vector<vector<int>>& arr) {
	    
	//Reversing each row
    for(int i=0 ; i<arr.size() ; i++){
        reverse(arr[i].begin(), arr[i].end());
    }
	
	// Transpose 
    for(int i=0 ; i<arr.size() ; i++){
        for(int j=i ; j<arr.size() ; j++){
            
            swap(arr[i][j], arr[j][i]);
        }
    }
}


int main(){

    int row = 3, col = 3;
 
    int** arr = (int**)malloc(row * sizeof(int*));

    for(int i=0; i<row; i++){
        arr[i] = (int*)malloc(col * sizeof(int));
    }
 
    cout << "\nEnter Array elements : \n";    input(arr, row, col);
 
    rotateMatrix(arr);
 
    cout << "\nRotated Matrix is : \n";    print(arr, row, col);
    
    free(arr);
 
    return 0;
}


