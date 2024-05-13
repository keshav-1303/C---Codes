#include <stdio.h>
#include <stdlib.h>
#define maxsize 100

void swap(int *i, int *j){
    int temp = *i;
    * i = *j;
    * j = temp;
}

int heap[maxsize];
int size = -1;

void new(){
    heap[0] = -1;
    size = 0;
}

void insert(int val){

    size++;
    int index = size;
    heap[index] = val;

    while(index > 1){

        int parent = index/2;

        if(heap[parent] < heap[index]){
            swap(&heap[parent], &heap[index]); 
            index = parent;
        }

        else{
            return ;
        }
    }
}

void printheap(){
    for(int i=0 ; i<=size ; i++){
        printf("%d ", heap[i]);
    }
    printf("\n");
}

void DeleteMax(){

    if(size == 0){
        printf("Nothing to delete\n");
        return ;
    }

    heap[1] = heap[size];
    size--;

    int i = 1;
    while(i < size){

        int leftindex = 2*i;
        int rightindex = 2*i + 1;

        if(leftindex < size && heap[leftindex] > heap[i]){
            swap(&heap[leftindex], &heap[i]);
            i = leftindex;
        }

        else if(rightindex < size && heap[rightindex] > heap[i]){
            swap(&heap[rightindex], &heap[i]);
            i = rightindex;
        }

        else{
            return ;
        }
    }
}

int main(){

    new();
    
    insert(30);
    insert(20);
    insert(50);
    insert(60);
    insert(40);

    printheap();

    DeleteMax();
    printheap();

    return 0;
}