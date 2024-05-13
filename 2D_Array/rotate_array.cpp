#include <bits/stdc++.h>
using namespace std;

void print(long long int *ans, int n){
	for(int i=0; i<n; i++)	  printf("%lld ",ans[i]);
	printf("\n");
}

void rotate(long long int* nums, int numsSize, int k){
    int n = numsSize;
    long long int temp[n];

    for(int i=0; i<n; i++){
        temp[(i+k)%n]=nums[i];
    }
    nums=temp;
    
    print(nums, n);
}

int main(){
	
    long long int nums[7] = {1,2,3,4,5,6,7}, k = 3;

    rotate(nums, 7, k);

	return 0;
}