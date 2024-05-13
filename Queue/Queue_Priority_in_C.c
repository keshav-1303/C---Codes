#include <stdio.h>
#include <stdlib.h>
#define print(arr, n)   {for(int i=0; i<n; i++)    printf("%d ",arr[i]);}   printf("\n");

struct queue{
    int size;
    int front;    // index of front element - 1
    int rear;     // index of rear element
    int *arr;
};

int isFull(struct queue* q){
    if( q->rear == q->size - 1)    return 1;
    return 0;
}

int isEmpty(struct queue* q){
    if( q->rear == q->front)    return 1;
    return 0;
}

void enqueue(struct queue* q, int k){
    if(isFull(q)){
        printf("Queue full !!!");
    }
    else{

        int i = q->front + 1;

        while(q->arr[i] < k){
            i++;
        }

        for(int j = q->size - 1 ; j >= i + 1 ; j--){
            q->arr[j] = q->arr[j-1];
        }

        q->arr[i] = k;

        // print(q->arr, q->size);

        q->rear++;

    }
}

void dequeue(struct queue* q){
    if(isEmpty(q)){
        printf("Underflow !!!");
    }
    else{
        q->front++;
        q->arr[q->front] = 0;
        // print(q->arr, q->size);
    }
}

void Print(struct queue* q){

    int i = q->front + 1;

    while(i < q->rear + 1){
        printf("%d ", q->arr[i]);
        i++;
    }

    printf("\n");
}

int main(){

    struct queue* q = (struct queue*) malloc (sizeof(struct queue));

    q -> size = 10;
    q -> front = -1;
    q -> rear = -1;

    q -> arr = (int*) malloc (sizeof(int)*q->size);

    enqueue(q, 23);
    enqueue(q, 2);
    enqueue(q, 22);
    enqueue(q, 25);
    enqueue(q, 63);
    enqueue(q, 52);
    enqueue(q, 678);

    Print(q);

    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);

    Print(q);
 
    return 0;
}

