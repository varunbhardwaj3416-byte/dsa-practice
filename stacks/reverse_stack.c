#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct stack {
    int * stack ; 
    int top ; 
    int size ; 
    int capacity ; 
} ; 

struct stack * createStack(int capacity) {
    struct stack * new = (struct stack *) malloc(sizeof(struct stack)) ; 
    if (!new) {
        printf("Heap is full \n") ; 
        return NULL ; 
    }
    new -> stack = (int *) malloc(sizeof(int) * capacity) ; 
    new -> top = -1 ; 
    new -> capacity = capacity ; 
    new -> size = 0 ; 
    return new ; 
}
void doubleStack(struct stack * stack) {
    int * new = realloc(stack -> stack  , sizeof(int) * stack -> size * 2) ; 
    if (!new) {
        printf("Can't double the stack , Try again \n") ; 
        return ; 
    }
    stack -> stack = new ; 
    stack -> capacity = stack -> capacity * 2 ; 

}

void push (struct stack * stack , int x) {
    if (stack == NULL) return ; 
    if (stack -> size == stack -> capacity) doubleStack(stack) ; 
    stack -> stack[++stack -> top] = x ; 
    stack -> size += 1 ; 
}

int pop(struct stack * stack) {
    if (stack -> top == -1) return INT_MIN ; 
    stack -> size -= 1 ; 
    return stack -> stack [stack -> top--] ; 

}

int isEmptyStack(struct stack * stack) {
    return (stack -> top == -1) ; 
}

void insertAtBottom(struct stack * stack , int element) {
    if (isEmptyStack(stack)) {
        push(stack , element) ; 
        return ; 
    }
    int topElement = pop(stack) ; 
    insertAtBottom(stack , element) ; 
    push(stack , topElement) ; 
}

void reverseStack(struct stack * stack) {
    if (isEmptyStack(stack)) return ; 
    int top = pop(stack) ; 
    reverseStack(stack) ; 
    insertAtBottom(stack , top) ; 
}
void displayStack (struct stack * stack) {
    if (stack == NULL) return ; 
    int tempTop = stack -> top ;
    while(tempTop != -1) {
        printf("%d. %d \n" , tempTop + 1 , stack -> stack[tempTop]) ; 
        tempTop -= 1 ;
    }
}
void freeStack (struct stack * stack) {
    if (stack == NULL) return ; 
    free(stack -> stack) ; 
    free(stack) ; 
    printf("Freed memory \n") ; 
}


int main() {
    int t , n , data ; 
    printf("No of time you want to run this program : \n") ; 
    scanf("%d" , &t) ; 
    struct stack * stack = createStack(10000) ; 
    while(t--) {
        printf("No of elements ? : ") ; 
        scanf("%d" , &n) ; 
        while(n--) {
            printf("\nEnter the element : ") ; 
            scanf("%d" , &data) ; 
            push(stack , data) ; 
        }
        printf("\nBefore Reversal \n") ;  
        displayStack(stack) ; // display stack before reversal 
        reverseStack(stack) ; 
        printf("\nAfter reversal : \n") ; 
        displayStack(stack) ; // display reversed stack 
        stack -> top = -1 ; 
        stack -> size = 0 ; 
        printf("\n") ; 
    }
    freeStack(stack) ; 
    return 0;
}