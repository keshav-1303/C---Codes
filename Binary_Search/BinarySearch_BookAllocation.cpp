/* You are given an array ‘pages’ of integer numbers. In this array, the ‘pages[i]’ represents the number of pages in the ‘i-th’ book. There are ‘m’ number of students, and the task is to allocate all the books to the students. 

Allocate books in a way such that:

Each student gets at least one book.
Each book should be allocated to a student.
Book allocation should be in a contiguous manner.
 
You have to allocate the books to ‘m’ students such that the maximum number of pages assigned to a student is minimum.                                                                                                    */

#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &arr, int m, int n, int mid){

    int StudCount = 0;  int pagesum = 0;

    for(int i=0; i<m; i++){

        pagesum+=arr[i];

        if(pagesum > mid){
            pagesum = arr[i];
            StudCount++;
        }
    }

    if (StudCount > n)   return false;
    else    return true;
}

int AllocateBooks(vector<int> &arr, int m, int n){    //m:books   n:students

    int s = 0;
    int sum = 0;
    
    for(int i = 0; i<n; i++) {
        sum += arr[i];
    }
    int e = sum;
    int ans = -1;
    int mid = s + (e-s)/2;
    
    while(s<=e)
    {
        if(isPossible(arr,n,m,mid)) {
            //cout<<" Mid returned TRUE" << endl;
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

int main(){

    int m=4, n=2;
    // cout << "Enter number of books : ";     cin >> m;

    // cout << "Enter number of students : "    cin >> n;
	
    vector<int> v = {10, 20, 30, 40};

    cout << "Answer is " << AllocateBooks(v, m, n);

	return 0;
}