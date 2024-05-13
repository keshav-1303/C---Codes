#include <bits/stdc++.h> 
using namespace std;

// https://www.codingninjas.com/codestudio/problems/sudoku-solver_699919?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

// CAN SUDOKU HAS MORE THAN 1 SOLUTION ???

void print(vector<vector<int>> &arr, int n){

    cout << endl;
        for(int i=0 ; i<9 ; i++){
            for(int j=0 ; j<9 ; j++){
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    
}

bool isSafe(int row, int col, vector<vector<int>> &sudoku, int c){

    for(int i=0 ; i<9 ; i++){

        int c1 = 3*(row/3) + i/3;
        int c2 = 3*(col/3) + i%3;

        if(sudoku[row][i] == c)    return 0;

        if(sudoku[i][col] == c)    return 0;

        if( sudoku[c1][c2] == c )    return 0;
    }

    return 1;
}

void solve(int x, int y, vector<vector<int>> &sudoku){

    if(x == 8 && y == 9){
    
        print(sudoku, 9);
        
        exit(0);
        return ;
    }

    if(y == 9){
        x++;
        y = 0;
    }

    if (sudoku[x][y] > 0)
        solve(x, y+1, sudoku);

    for(int c=1 ; c<=9 ; c++){     // for checking which value (1 - 9) will fit 

        if (isSafe(x, y, sudoku, c)) {

            sudoku[x][y] = c;
            solve(x, y + 1, sudoku);
            sudoku[x][y] = 0;     // if reaches here y+1 soln failed thus backtrack
        }
    }
}

void solveSudoku(vector<vector<int>>& sudoku){
    solve(0, 0, sudoku);
}

int main(){

    int n = 9;

    vector<vector<int>> arr (n, vector<int> (n, 0));
    //                     (row)            (col)

    cout << "Enter Sudoku to solve --> " << endl;

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            int temp;    cin >> temp;
            arr[i][j] = temp;
        }
    }

    solveSudoku(arr);

}