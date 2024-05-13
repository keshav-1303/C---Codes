#include <iostream>
using namespace std;

// Time Complexity : O(log n)

void BinarySearch(int *arr, int n, int key){

    int start=0, end=n-1;
    int mid=start+(end-start)/2;
    int ans=-1;

    while(start<=end){
        if (arr[mid]==key)    ans=mid+1;

        if (arr[mid]>key)    end = mid - 1;
        
        else    start = mid + 1;
        
        mid=start+(end-start)/2;
    }
    if(ans==-1)    cout<<"Element NOT Found!!!\n";
    else    cout<<"Element found at "<<ans<<endl;
}


int main(){
	
    int n;   cout<<"Enter n : ";    cin>>n;
    int *arr;
    arr=(int*)malloc(n*sizeof(int));

    for(int i=0; i<n; i++){
        cout<<"Enter element"<<i+1<<" : ";
        cin>>arr[i];
    }

    int key;   cout<<"Enter key : ";    cin>>key;

    BinarySearch(arr, n, key); 

	return 0;
}