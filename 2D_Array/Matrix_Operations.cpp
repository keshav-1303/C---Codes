// Matrix Operations...
#include <bits/stdc++.h>
using namespace std;

void input(int **arr, int row, int column){ //take matrix input
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            cin >> arr[i][j];
        }
    }
}

void print(int **arr, int row, int column){ // print matrix
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++)     cout << arr[i][j] << " ";
        cout << endl;
    }
}

void transpose(int **arr, int row, int column){
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++)    cout << arr[j][i] << " ";
        cout << endl;
    }
}

void sum(int **arr, int **brr, int row, int column){

    int **plus = (int**)malloc(row * sizeof(int*));
    for(int i=0; i<row; i++)    plus[i] = (int*)malloc(column * sizeof(int));
    
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            plus[i][j]=arr[i][j]+brr[i][j];
        }
    }
    print(plus,row,column);
    free(plus);
}

void multiply(int **arr, int **brr, int row, int column){      //   ****MOST IMPORTANT****

    int **mul = (int**)malloc(row * sizeof(int*));
    for(int i=0; i<row; i++)    mul[i] = (int*)malloc(column * sizeof(int));

    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            int sum=0;
            for(int k=0; k<column; k++){  //k must be = (column of 1st matrix or row of 2nd matrix).
                sum+=arr[i][k]*brr[k][j];
            }
            mul[i][j]=sum;
        }
    }
    print(mul,row,column);
    free(mul);
}


int main(){

    int row = 3, column = 3;

    int **arr = (int**)malloc(row * sizeof(int*));
    for(int i=0; i<row; i++)    arr[i] = (int*)malloc(column * sizeof(int));

    int **brr = (int**)malloc(row * sizeof(int*));
    for(int i=0; i<row; i++)    brr[i] = (int*)malloc(column * sizeof(int));
    
    cout << "Enter Matrix 1 ...\n";    input(arr, row, column);
    cout << "Enter Matrix 2 ...\n";    input(brr, row, column);

    cout << "\nTranspose is ...\n";    transpose(arr, row, column);
    cout << "\nSum is ...\n";    sum(arr, brr, row, column);
    cout << "\nProduct is ...\n";    multiply(arr, brr, row, column);

    free(arr);
    free(brr);
    
	return 0;
}