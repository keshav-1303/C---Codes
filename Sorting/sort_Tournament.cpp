#include<stdio.h>
#include<stdlib.h>

int max(int a,int b){
    if (a > b)
        return a;
    return b;
}

int swap(int *i,int *j){
    int temp =*i;
    *i=*j;
    *j=temp;
}

void printArr(int arr[],int n){
    for (int i = 0;i < n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

//running time O(n);
void nextMaxi(int arr[],int n){
    int max, nextmax;
    max = arr[0]; nextmax = arr[1];
    if(max < nextmax) swap(&max,&nextmax);

    for (int i = 2;i <= n-1;i++){
        if(arr[i] >= max){
            nextmax=max; 
            max = arr[i];
        }
        else if(arr[i]>nextmax)
            nextmax = arr[i];
    }
    printf("Max = %d\nNext Max = %d \n",max,nextmax);
}

//tournament
void match(int arr[],int size,int n){
    while (n !=1){
        for (int i = 2*n-2;i >= n;i-=2){
            arr[i/2] = max(arr[i],arr[i+1]);
        }
        n = n/2;
    }
}
void tournament(int arr[],int n){
    int flag = 0;
    int last;
    if (n & 1){
        flag =1;
        n--;
        last = arr[n];
    }
    
    int* tour = (int*) calloc(2*n,sizeof(int));
    int start = 0;
    for (int i = n;i <= 2*n-1;i++){
        tour[i] = arr[start++]; 
    }

    //compute the match;
    match(tour,2*n,n);
    // printArr(tour,2*n);
    int i = 0;
    while (tour[i] == 0) i++;
    int maxi = tour[i];
    int nextMax = -1;
    while (i < n){
        if (tour[2*i] == maxi){
            nextMax = max(nextMax,tour[2*i+1]);
            i = 2*i;
        }
        else{
            nextMax = max(nextMax,tour[2*i]);
            i = 2*i+1;
        }
    }

    if (flag == 0)
        printf("Max = %d\nNext Max = %d \n",maxi,nextMax);
    else{
        if (maxi > last){
            printf("Max = %d\nNext Max = %d \n",maxi,max(nextMax,last));
        }
        else{
            printf("Max = %d\nNext Max = %d \n",last,maxi);

        }
    }

}

int main(){
    int n, m,  i , num;   
    //input;
    printf("Enter no of elements : ");
    scanf("%d",&n);
    
    int arr[n];
    for(i=0; i< n; i++){
        scanf("%d",&arr[i]);    
    }
    printf("Using brute force : \n");
    nextMaxi(arr,n);

    printf("\nUsing Tournament : \n");

    //only workable for all number of terms;
    tournament(arr,n);
}