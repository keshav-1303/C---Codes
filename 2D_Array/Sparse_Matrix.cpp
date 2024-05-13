#include <bits/stdc++.h>
using namespace std;

struct  sparse{
    int *Row;
    int *Col;
    int *Data;
};

void print(struct sparse* s, int row, int col){
    int c = 0 ;
    for(int i=0 ; i<row ; i++){
        for(int j=0 ; j<col ; j++){
            if(i == s->Row[c] - 1  &&  j == s->Col[c] - 1){
                cout << s->Data[c] << " ";
                c++;
            }
            else    cout << 0 << " ";
        }
        cout << endl;
    }
}

struct sparse* ADD(struct sparse* s){

}

int main(){

    int row = 3, col = 3;
    // cout << "Enter Rows : ";     cin >> row;
    // cout << "Enter Columns : ";     cin >> col;

    // int arr[row][col];

    // int count = 0;

    // for(int i=0 ; i<row ; i++){
    //     for(int j=0 ; j<col ; j++){
    //         cin >> arr[i][j];
    //         if(arr[i][j] != 0)     count++;
    //     }
    // }

    int arr[3][3] = { {1, 0, 2},
                      {0, 8, 0},
                      {0, 7, 8} }

    int arr1[3][3] = { {1, 0, 0},
                      {3, 0, 0},
                      {0, 7, 8} }

    struct sparse *s = (struct sparse *)malloc(sizeof(struct sparse));
    s->Row = (int*)malloc(sizeof(int)*count);
    s->Col = (int*)malloc(sizeof(int)*count);
    s->Data = (int*)malloc(sizeof(int)*count);
    int c = 0;
    for(int i=0 ; i<row ; i++){
        for(int j=0 ; j<col ; j++){
            if(arr[i][j] != 0){
                s->Row[c] = i + 1;
                s->Col[c] = j + 1;
                s->Data[c++] = arr[i][j];
            }
        }
    }

    struct sparse *s1 = (struct sparse *)malloc(sizeof(struct sparse));
    s1->Row = (int*)malloc(sizeof(int)*count);
    s1->Col = (int*)malloc(sizeof(int)*count);
    s1->Data = (int*)malloc(sizeof(int)*count);
    int c1 = 0;
    for(int i=0 ; i<row ; i++){
        for(int j=0 ; j<col ; j++){
            if(arr1[i][j] != 0){
                s1->Row[c] = i + 1;
                s1->Col[c] = j + 1;
                s1->Data[c++] = arr[i][j];
            }
        }
    }

    // for(int i=0 ; i<count ; i++)    cout << s->Row[i] << " ";
    // cout << endl;

    // for(int i=0 ; i<count ; i++)    cout << s->Col[i] << " ";
    // cout << endl;

    // for(int i=0 ; i<count ; i++)    cout << s->Data[i] << " ";
    // cout << endl;

    // print(s, row, col);

    struct sparse* add = ADD(s1, s);
    print(add);
    
    return 0;
}

