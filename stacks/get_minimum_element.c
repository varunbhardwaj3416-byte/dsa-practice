#include <stdio.h>
#include <stdlib.h>

struct minStack{
    int * stack ; 
    int * minStack ; 
    int topStack ; 
    int topMinStack ;
    int size ;  
} ; 

struct minStack * createMinStack(int size){
    struct minStack * new = (struct minStack *) malloc(sizeof(struct minStack)) ; 
    if (!new) {
        // heap is full 
        printf("Heap is full , Try again \n") ; 
        return NULL ; 
    }
    new -> size = size ; 
    new -> stack = (int *) malloc(sizeof(int) * size) ; 
    new -> minStack = (int *) malloc(sizeof(int) * size) ;
    new -> topStack = -1 ; 
    new -> topMinStack = -1 ; 
    return new ;     
}

void doubleMinStack(struct minStack * minStack , int decision){
        // decision is 0 when stack is full 
        // decision is 1 when minStack is full there can a scenario so we are considering it 
        if (!decision){
            int * new = realloc(minStack -> stack , sizeof(int) * minStack -> size * 2) ; 
            if (!new) {
                // didn't get the memory 
                printf("Sorry heap is full \n") ; 
                // old memory is preserved 
            }
            else {
                minStack -> size = minStack -> size * 2 ; 
            }
        }
        else {
            // if we want to expand minStack in struct minStack 
            int * new = realloc(minStack -> minStack , minStack -> size * 2) ; 
            if (!new) {
                printf("Heap is full \n") ; 
            }
            else {
                // memory got allocated 
            }
        }
}

void pushStack(struct minStack * minStack , int x) {
    if (minStack -> topStack + 1 == minStack -> size) {
        // double the size 
        doubleMinStack(minStack , 0) ;  
    }
    minStack -> stack[++minStack -> topStack] = x ; 
    printf("Pushed %d \n" , x) ; 
    return ;
}

void pushMinStack(struct minStack * minStack , int x) {
    if (minStack -> topMinStack + 1 == minStack -> size) {
        doubleMinStack(minStack , 1) ; 
    }
    minStack -> minStack[++minStack -> topMinStack] = x ; 
    printf("Pushed %d \n" , x) ; 
    return; 

}

int getMin(struct minStack * minStack){
    if (minStack -> topMinStack == -1) {
        return INT_MIN ;    
    }
    else {
        return minStack -> minStack[minStack -> topMinStack] ; 
    }
}

void freeMinStack (struct minStack * minStack) {
    if (!minStack) return ; 
    free(minStack -> stack) ; 
    free(minStack -> minStack) ; 
    free(minStack) ; 
    printf("Memory Freed \n") ;
}



int main() {
    int t , n , element ; 
    printf("Enter the time you want to run the progran \n") ; 
    scanf("%d" , &t) ; 
    while (t--){
        printf("Enter the no of elements you want to enter : ") ; 
        printf("\n") ; 
        int n ; 
        scanf("%d" , &n) ; 
        struct minStack * minStack = createMinStack(n) ; 
        while(n--){
            printf("Enter : ") ; 
            scanf("%d" , &element) ; 
            pushStack(minStack , element) ; 
            // when to push in minStack when topMinStack == -1 and 
            if (minStack -> topMinStack == -1 || element <= minStack -> minStack[minStack -> topMinStack]) {
                pushMinStack(minStack , element) ; 
            }
        }
        // popping and showing the minimum element list 
        // O(1) for seeing the minimum element in Stack 
        // O(n) for auxillary stack space here with the name of minStack 
        int original = minStack -> topMinStack ; 
        while(minStack -> topMinStack != -1) {
                printf("%d\n" , minStack -> minStack[minStack -> topMinStack--]) ; 
        }
        printf("\n") ; 
        minStack -> topMinStack = original ; 
        printf("Now : \n") ; 
        while (minStack -> topStack != -1) {
            int top = minStack -> stack[minStack -> topStack--] ; 
            printf("Top element is %d \n" , top) ; 
            if (top == getMin(minStack)) { 
                // pop 
                minStack -> topMinStack -= 1 ;
                printf("Current minimum is %d \n" , top) ;  
            }
            else {
                printf("Current minimum is %d \n" ,minStack -> minStack[minStack -> topMinStack]) ; 
            } 
            printf("\n") ; 
        }
        freeMinStack(minStack) ; 
    }
    return 0;
}