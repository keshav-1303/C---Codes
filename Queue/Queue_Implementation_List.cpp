#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct queue{
    int size;
    int front;    // index of front element
    int rear;     // index of rear element
    struct node* arr;
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
        struct node* p;
        p->data = k;
        p->next = q->arr;
        q->rear++;
    }
}

void dequeue(struct queue* q){
    if(isEmpty(q)){
        printf("Underflow !!!");
    }
    else{
        q->front++;
    }
}

void Print(struct queue* q){

    int index = 0;
    int i = q->front + 1;

    while(index < i){
        q->arr = q->arr->next;
    }

    while(i < q->size - 1){
        printf("%d ", q->arr->data);
        i++;
    }

    printf("\n");
}

int main(){

    struct queue* q = (struct queue*) malloc (sizeof(struct queue));

    q -> size = 5;
    q -> front = -1;
    q -> rear = -1;

    q -> arr = NULL;

    enqueue(q, 23);
    enqueue(q, 21);
    enqueue(q, 63);
    enqueue(q, 678);

    // printf("Is Queue Empty --> %d\n", isEmpty(q));

    Print(q);

    printf("Is Queue Empty --> %d\n", isEmpty(q));

    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);

    printf("Is Queue Empty --> %d\n", isEmpty(q));
 
    return 0;
}

