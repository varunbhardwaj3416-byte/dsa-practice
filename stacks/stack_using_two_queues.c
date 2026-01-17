#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct stack {
    int * queue1 ; 
    int * queue2 ; 
    int front1 , rear1 ; 
    int front2 , rear2  ; 
    int capacity ; // size and capacity for both stack will be same 
    int size1 , size2 ; 
} ; 


struct stack * createStack(int size) {
    struct stack * new = (struct stack *) malloc(sizeof(struct stack)) ; 
    if (!new) {
        printf("Heap is full , Try again \n") ; 
        return NULL ; 
    }
    new -> capacity = size ; // will try current size with help of top 
    new -> queue1 = (int *) malloc(sizeof(int) * size) ;
    new -> queue2 = (int *) malloc(sizeof(int) * size) ; 
    if (!new -> queue1 || !new -> queue2) {
        printf("Heap is full , got this in allocating memory for stack inside struct queue , Try again \n") ; 
        return NULL ; 
    }
    new -> front1 = -1 ;
    new -> rear1 = -1 ; 
    new -> front2 = -1 ;
    new -> rear2 = -1 ;  
    new -> size1 = new -> size2 = 0 ; 
    return new ; 
}

// now write for enQueue , push , pop , display the stack , freeing up memory 

void enQueue(struct stack * stack , int data , int queueNo) {
    if (stack == NULL) return ; 
    // here deQueue can be seen as element moving our from one queue to another but at the same time they are 
    // being inserted into another queue 
    if (queueNo == 2) { 
        if (stack -> front2 == -1) stack -> front2 = 0 ; 
        stack -> queue2[++stack -> rear2] = data ; 
        stack -> size2 += 1 ; 
    }
    else {
        // when queueNo is 1 
        if (stack -> front1 == -1) stack -> front1 = 0 ; 
        stack -> queue1[++stack -> rear1] = data ; 
        stack -> size1 += 1 ; 
    }
    
}


void push(struct stack * stack , int data) {
    if (stack -> size2 == 0) {
        // push on to queue1
        enQueue(stack , data , 1) ; 
        return ; 
    }
    // push to queue 2 
    enQueue(stack , data , 2) ; 
}

void pop(struct stack * stack , int * found , int * data) {
    if (stack -> size1 == 0 && stack -> size2 == 0) {
        *found = 0 ; 
        return ; 
    }
    *found = 1 ; 
    if (stack -> size2 == 0) {
        // dequeue queue1 
        while(stack -> front1 != stack -> rear1) {
            enQueue(stack , stack -> queue1[stack -> front1++] ,2) ; 
        }
        *data = stack -> queue1[stack -> front1] ; 
        stack -> front1 = stack -> rear1 = -1 ; 
        stack -> size1 = 0 ; 
    }
    else {
        while(stack -> front2 != stack -> rear2) {
            enQueue(stack , stack -> queue2[stack -> front2++] , 1) ; 
        }
        *data = stack -> queue2[stack -> front2] ; 
        stack -> front2 = stack -> rear2 = -1 ; 
        stack -> size2 = 0 ;
    }

}
void freeStack(struct stack * stack) {
    if (!stack) return ;
    free(stack -> queue1) ; 
    free(stack -> queue2) ; 
    free(stack) ; 
    printf("Memory freed \n") ; 
}
void displayStack(struct stack * stack) {
    if (!stack) return ; 
    while(stack -> front1 != -1 || stack -> front2 != -1) {
        int found = 0 , data ; 
        int size = stack -> size1 + stack -> size2 ; 
        pop(stack , &found , &data) ; 
        printf("%d. %d\n" , size , data ) ; 
    } 
    printf("Stack emptied\n") ; 
}


int main() {
  int t , element ; 
    printf("No of time you want to run the program : \n") ; 
    scanf("%d" , &t) ; 
    struct stack * stack = createStack(100000) ; 
    while(t--){
        int choice ; 
        while (1) {
            printf("\n1. Enter 1 for Push operation : ") ; 
            printf("\n2. Enter 2 for Pop operation : ") ;
            printf("\n3. Enter 3 for display of stack : ") ;  
            printf("\n4. Enter 4 for Exit : ") ;  
            scanf("%d" , &choice) ; 
            if (choice == 4) break ; 
  
            switch(choice) {
                case 1 : 
                    printf("Enter the element : ") ; 
                    scanf("%d" , &element) ; 
                    push(stack , element) ; 
                    printf("\n") ; 
                    break ; 
                case 2 :  
                    int data , found ; 
                    pop(stack , &found , &data) ; 
                    if(found){
                        printf("Popped element is : %d \n" , data) ; 
                    }
                    else {
                        printf("Stack is empty ") ; 
                    }
                    break ; 
                case 3 : 
                    displayStack(stack) ; 
                    break ;  
                default : 
                    printf("Wrong choice entered try again : \n") ; 
            }
            printf("\n") ; 
    }
    stack -> front1 = stack -> front2 = stack -> rear1 = stack -> rear2 = -1 ; 
    stack -> size1 = stack -> size2 = 0 ; 
    }
    printf("Program Exited \n") ; 
    freeStack(stack) ; 
    return 0;

}