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

void push(struct queue* q, int k){
    if(isFull(q)){
        printf("Queue full !!!");
    }
    else{
        q->rear++;
        q->arr[q->rear] = k;
        print(q->arr, q->size);
    }
}

void pop(struct queue* q){
    if(isEmpty(q)){
        printf("Underflow !!!");
    }
    else{
        q->front++;
        q->arr[q->front] = 0;

        if(q->front == q->rear){     // for efficient memory utilisation...
            q->front = -1;
            q->rear = -1;
        }

        print(q->arr, q->size);
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

int top(struct queue* q){
    return q->arr[q->front+1];
}

int main(){

    struct queue* q = (struct queue*) malloc (sizeof(struct queue));

    q -> size = 5;
    q -> front = -1;
    q -> rear = -1;

    q -> arr = (int*) malloc (sizeof(int)*q->size);

    push(q, 23);
    push(q, 21);
    push(q, 63);
    push(q, 678);

    printf("\nIs Queue Empty --> %d\n", isEmpty(q));

    printf("Topmost element -> ");    printf("%d\n", q->arr[q->front+1]);

    printf("\nEntered queue is ...\n");
    Print(q);
    printf("\n");

    pop(q);
    pop(q);
    pop(q);
    pop(q);

    printf("Is Queue Empty --> %d\n", isEmpty(q));

    push(q, 2);
    push(q, 4);

    
 
    return 0;
}

