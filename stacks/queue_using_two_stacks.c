#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int *data;
    int capacity;
    int size;
    int top;
};

struct Stack* createStack(int capacity) {
    struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
    if (!s) return NULL;

    s->data = (int *)malloc(sizeof(int) * capacity);
    if (!s->data) {
        free(s);
        return NULL;
    }

    s->capacity = capacity;
    s->size = 0;
    s->top = -1;
    return s;
}

void push(struct Stack *s, int value) {
    if (s->size == s->capacity) {
        s->capacity *= 2;
        int *temp = (int *)realloc(s->data, sizeof(int) * s->capacity);
        if (!temp) {
            printf("Memory reallocation failed\n");
            return;
        }
        s->data = temp;
    }

    s->top++;
    s->data[s->top] = value;
    s->size++;
}

int pop(struct Stack *s) {
    if (s->size == 0) {
        printf("Stack underflow\n");
        return -1;
    }

    int val = s->data[s->top];
    s->top--;
    s->size--;
    return val;
}

void freeStack(struct Stack *s) {
    if (!s) return;
    free(s->data);
    free(s);
    printf("Memory Freed \n") ; 
}

void enQueue(struct Stack * firstStack , struct Stack * secondStack , int data) {
    if (firstStack == NULL || secondStack == NULL) {
        printf("Enqueue failed \n") ; 
        return ; 
    }
    push(firstStack , data) ; // pushed onto first stack 
}

void deQueue(struct Stack * firstStack , struct Stack * secondStack) {
    // if second Stack top is -1 , transfer all the elements from first stack to another 
    if (secondStack -> top == -1 && firstStack -> top == -1) {
        printf("Queue is empty \n") ; 
        return ; 
    }
    if (secondStack -> top == -1) {
        while(firstStack -> top != -1) {
            secondStack -> data [++secondStack -> top] = pop(firstStack) ; 
            secondStack -> size += 1 ; 
        }
    }
   printf("Dequeued element is %d \n" , pop(secondStack)) ; 
    
}


int main() {
    int t , element ; 
    printf("No of time you want to run the program : \n") ; 
    scanf("%d" , &t) ; 
    // creation of two stacks 
    struct Stack * first = createStack(10000) , *second = createStack(100000) ; 

    while(t--){
        int choice ; 
        while (1) {
            printf("\n1. Enter 1 for Enqueue operation : ") ; 
            printf("\n2. Enter 2 for Dequeue operation : ") ; 
            printf("\n3. Enter 3 for Exit : ") ;  
            scanf("%d" , &choice) ; 
            if (choice == 3) break ; 
  
            switch(choice) {
                case 1 : 
                    printf("Enter the element : ") ; 
                    scanf("%d" , &element) ; 
                    enQueue(first , second , element) ; 
                    printf("\n") ; 
                    break ; 
                case 2 :  
                    deQueue(first , second) ; 
                    break ;  
                default : 
                    printf("Wrong choice entered try again : \n") ; 
            }
    }
    first -> top = -1 ; 
    first -> size = 0 ; 
    second -> top = -1 ; 
    second -> size = -1 ; 
    }
    printf("Program Exited \n") ; 
    freeStack(first) ; 
    freeStack(second) ; 
    return 0;
}