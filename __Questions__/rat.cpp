// Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
// Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.

#include <bits/stdc++.h>
using namespace std;
 
// Here, the parameter is an array of pointers
void input(int** arr, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++) {
            arr[i][j] = i + j;
        }
    }
}

void print(int** arr, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
 
// Program to pass the 2D array to a function in C
int main(){

    int m = 5;
    int n = 5;
 
    // dynamically create an array of pointers of size `m`
    int **arr = (int **)malloc(m * sizeof(int *));
 
    // dynamically allocate memory of size `n` for each row
    for (int r = 0; r < m; r++) {
        arr[r] = (int *)malloc(n * sizeof(int));
    }
 
    input(arr, m, n);
 
    // print 2D array
    print(arr, m, n);
 
    // deallocate memory
    for (int i = 0; i < m; i++) {
        free(arr[i]);
    }
    free(arr);
 
    return 0;
}

// bool findPath(vector<vector<int>> &arr){

//     int m = arr.size();
//     int n = arr[0].size();

//     vector <vector<int>> visited;
//     for(int i=0; i<m; i++){
//         for(int j=0; j<n; j++){
//             visited[i][j] = 0;
//         }
//     }



// }

// int main(){

//     int m = 4, n = 4;

//     int arr[m][4] = {{1, 0, 0, 0},
//                      {1, 1, 0, 1},
//                      {1, 1, 0, 0},
//                      {0, 1, 1, 1}};

//     // cout << "Can rat reach destination -> " << findPath(arr) << endl;

//     print(arr, m, n);
	
// 	return 0;
// }