#include <bits/stdc++.h>
using namespace std;


int main(){

    int row,col;
    printf("Enter Number of rows : ");
    scanf("%d",&row);

    printf("Enter Number of columns : ");
    scanf("%d",&col);

	int matrix[row][col];
    
    cout<<"Enter matrix...\n";
    for(int i=0; i<row; i++){     //input
        for(int j=0; j<col; j++){
            // cout<<"Enter element a("<<i+1<<","<<j+1<<") : ";
            cin>>matrix[i][j];
        }
    }
    
    vector<int> a;

    int startrow=0, endrow=row-1;
    int startcol=0, endcol=col-1;

    int count=0, total=row*col;

    while(count<total)
    {
        for (int j = startcol; j <= endcol && count<total; j++){ // right
            a.push_back(matrix[startrow][j]);
            count++;
        }
        startrow++;
    
        for (int j = startrow; j <= endrow && count<total; j++){ // down
            a.push_back(matrix[j][endcol]);
            count++;
        }
        endcol--;
        
        for (int j = endcol; j >= startcol && count<total; j--){ // left
            a.push_back(matrix[endrow][j]);
            count++;
        }
        endrow--;
        
        for (int j = endrow; j >= startrow && count<total; j--){ // up
            a.push_back(matrix[j][startcol]);
            count++;
        }
        startcol++;
    }
    
        for(int k=0; k<a.size(); k++)   cout<<a[k]<<"\n";
        cout<<endl;

	return 0;
}