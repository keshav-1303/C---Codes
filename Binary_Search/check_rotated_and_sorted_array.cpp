// Given an array nums, return true if the array was originally sorted in non-decreasing order, 
// then rotated some number of positions (including zero). Otherwise, return false.
// There may be duplicates in the original array.

#include <bits/stdc++.h>
using namespace std;

bool check(int* nums, int numsSize){
    
    int n=numsSize;    int count=0;
    for(int i=1; i<=n; i++){
        if(i==n){
            if(nums[0]<nums[n-1])    count++;
        }
        else{
            if(nums[i-1]>nums[i])   count++;
        }
    }

    if(count<=1)    return true;
    else    return false;
}

int main(){
	int nums[3]={1,1,1};

    int n=sizeof(nums)/sizeof(int);

    cout<<check(nums, n)<<endl;
	
	return 0;
}