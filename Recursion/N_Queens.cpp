#include <bits/stdc++.h> 
using namespace std;

void print(vector<vector<int>> &board, int n){
	for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<n ; j++){
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void addSolution(vector<vector<int>> &ans, vector<vector<int> > &board, int n) {

    // vector<int> temp;
    
    // for(int i=0; i<n; i++) {
    //     for(int j=0; j<n; j++) {
    //         temp.push_back(board[i][j]);
    //     }
    // }

    // ans.push_back(temp);

    print(board, n);
}

bool isSafe(int i, int col, int n, vector<vector<int>> &board){

	// No need to check for COLUMNs

	// for rows
	for(int j=col-1 ; j>=0 ; j--){
		if(board[i][j] == 1){
			return 0;
		}
	}

	// for diagonals
	for(int row=i-1, c=col-1 ; row>=0 && c>=0 ; row--, c--){
		if(board[row][c] == 1){
			return 0;
		}
	}
	for(int row=i+1, c=col-1 ; row<n && c>=0 ; row++, c--){
		if(board[row][c] == 1){
			return 0;
		}
	}

	return 1;
}

void solve(int col, int n, vector<vector<int>> &board, vector<vector<int>> &ans){

	// base case
	if(col == n){
        addSolution(ans, board, n);
		return ;
	}

	for(int row=0 ; row<n ; row++){	// col same row changes

		if(isSafe(row, col, n, board)){
            board[row][col] = 1;
			solve(col + 1, n, board, ans);
            board[row][col] = 0;
		}
	}
}

// vector<vector<int>> nQueens(int n){
void nQueens(int n){

	vector<vector<int>> board(n, vector<int>(n, 0));
	vector<vector<int>> ans;

	solve(0, n, board, ans);

	// return ans;
}

int main(){

    int n;    cout << "Enter n : ";     cin >> n;

    // vector<vector<int>> ans = nQueens(n);

    nQueens(n);

    // for(int i=0 ; i<ans.size() ; i++){
    //     for(int j=0 ; j<ans[0].size() ; j++){
    //         cout << ans[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
}