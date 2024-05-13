#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#define print(arr, n)   {for(int i=0; i<n; i++)    printf("%d ",arr[i]);}   printf("\n");

struct stack{
    int top;    // index of topmost element
    int size;
    int* arr;
};

int isFull(struct stack *s){
    if(s -> top == s -> size - 1)    return 1;
    return 0;
}

int isEmpty(struct stack *s){
    if(s -> top == -1)     return 1;
    return 0;
}

void push(struct stack *s, int k){
    if(isFull(s)){
        printf("Overflow\n");
    }
    else{
        s -> top++;
        s -> arr[s -> top] = k;
        // print(s->arr, s->size);
    }
}

void pop(struct stack *s){
    if(isEmpty(s)){
        printf("Underflow\n");
    }
    else{
        s -> arr[s -> top] = 0;
        s -> top--;
        // print(s->arr, s->size);
    }
}

int peek(struct stack *s){
    return s->arr[s->top];
}

void Print(struct stack* s){

    int i = 0;

    printf("\nStack entered --> ");

    while(i <= s->top ){
        printf("%d ", s->arr[i]);
        i++;
    }

    printf("\n");
    printf("\n");
}

int main(){

    struct stack *s = (struct stack*) malloc (sizeof(struct stack));

    // printf("Enter Number of elements in struct stack : ");     scanf("%d", s -> size);

    s -> size = 5;

    s -> top = -1;

    s -> arr = (int*) malloc (sizeof(int) * s->size);

    printf("Is stack empty --> %d\n", isEmpty(s));

    push(s, 34);
    push(s, 38);
    push(s, 32);
    push(s, 34);
    push(s, 38);
    push(s, 32);

    printf("Topmost Element is --> %d\n", peek(s));

    Print(s); 

    printf("Is stack empty --> %d\n", isEmpty(s));

    pop(s);
    pop(s);
    pop(s);
    pop(s);
    pop(s);
    pop(s);

    printf("Is stack empty --> %d\n", isEmpty(s));
 
    return 0;
}

