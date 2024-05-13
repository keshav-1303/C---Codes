#include <stdio.h>
#include <stdlib.h>

struct list{
    int data;
    struct list* next;
};

struct stack{
    int top;    // index of topmost element
    int size;
    struct list* arr;
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
        // printf("%d Inserted!!!\n", k);
    }
}

void pop(struct stack *s){
    if(isEmpty(s)){
        printf("Underflow\n");
    }
    else{
        s -> arr[s -> top] = '\n';
        s -> top--;
        // printf("Deleted!!!\n");
    }
}

int peek(struct stack* s){
    
}

void Print(struct stack *s){
    struct stack *temp = s;
    while(!isEmpty(temp)){
        printf("%d ", temp -> arr[temp -> top]);
        pop(temp);
    }
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
    printf("%d ", s -> arr[s -> top]);

    push(s, 38);
    printf("%d ", s -> arr[s -> top]);

    push(s, 32);
    printf("%d ", s -> arr[s -> top]);

    push(s, 34);
    printf("%d ", s -> arr[s -> top]);

    push(s, 38);
    printf("%d ", s -> arr[s -> top]);

    push(s, 32);
    printf("%d ", s -> arr[s -> top]);

    printf("\n");

    // Print(s);

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

