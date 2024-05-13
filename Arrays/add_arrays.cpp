// Given 2 numbers in form of arrays, give their sum as resulting array.

#include <bits/stdc++.h>
using namespace std;

void print(int *arr, int n){
    for(int i=0; i<n; i++){  
        if(i==0){
            while(arr[i]==0)    i++;
        } 
        cout<<arr[i];
    }
    cout<<endl;
}

void add(int *arr, int m, int *brr, int n){
    int c=max(m,n); 
    int size=max(m,n)+1; 
    int arr3[size], arr1[size], arr2[size], c1=0, c2=0;

    for(int i=0; i<size; i++){
        if(i<size-m)    arr1[i]=0;
        else    arr1[i]=arr[c1++];
        arr3[i]=0;
    }

    for(int i=0; i<size; i++){
        if(i<size-n)    arr2[i]=0;
        else    arr2[i]=brr[c2++];
    }
  
    for(int i=size-1; i>=0; i--){
        int temp=arr1[i]+arr2[i];
        if(temp<=9){
            arr3[i]+=temp;
        }
        else{
            arr3[i]+=temp-10;
            arr3[i-1]++;
        }
    }
    print(arr3, size);
}

int main(){

        int m,n;    
        cout<<"Enter m : ";    cin>>m;
        cout<<"Enter n : ";    cin>>n;

        int arr1[m];     
        cout<<"Enter arr1 elements : ";    for(int i=0; i<m; i++)   cin>>arr1[i];

        int arr2[n];     
        cout<<"Enter arr2 elements : ";    for(int i=0; i<n; i++)   cin>>arr2[i];

        add(arr1, m, arr2, n);
    
	return 0;
}