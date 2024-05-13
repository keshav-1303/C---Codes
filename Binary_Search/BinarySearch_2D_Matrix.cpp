// https://leetcode.com/problems/search-a-2d-matrix/description/

// You are given an m x n integer matrix matrix with the following two properties:
// Each row is sorted in non-decreasing order.
// The first integer of each row is greater than the last integer of the previous row.
// Given an integer target, return true if target is in matrix or false otherwise.
// You must write a solution in O(log(m * n)) time complexity.


#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector <vector<int>> matrix, int target) {

    int row=matrix.size();
    int col=matrix[0].size();
        
    int s=0, e=row*col-1;
    int mid=s+(e-s)/2;

    while(s <= e){

       int element = matrix[mid/col][mid%col];

        if(target == element)    return true;

        if(target > element)    s=mid+1;
        
        else    e=mid-1;

        mid=s+(e-s)/2;
    }

    return false;
}

int main(){

    vector <vector<int>> matrix;

    int row, col;

    cout<<"Enter No of rows : ";    cin>>row;
    cout<<"Enter No of columns : ";    cin>>col;

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            int temp;   cin>>temp;            

            matrix.push_back(temp);
        }
    }

    int target;    cout<<"Enter target : ";    cin>>target;

    cout<<searchMatrix(matrix, target)<<endl;

}