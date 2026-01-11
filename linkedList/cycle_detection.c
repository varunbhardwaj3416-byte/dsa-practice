#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

struct node* newNode(int value) {
    struct node *n = (struct node*)malloc(sizeof(struct node));
    n->data = value;
    n->next = NULL;
    return n;
}

void createLinkedList(int n , int cycle) {
    int x;
    struct node *curr = NULL;

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);

        if (head == NULL) {
            head = newNode(x);
            curr = head;
        } else {
            curr->next = newNode(x);
            curr = curr->next;
        }
    }
    if(cycle) curr -> next = head ; 
}

void floydCycleDetection(){
        if (head == NULL) return ; 

        struct node * tortoise = head  , *hare = head ;
        int startHead = 0 ;
        while(hare) {
            if (hare == tortoise && startHead) {
                // cycle detected 
                printf("Cycle exists \n") ; 
                return ; 
            }
            startHead = 1 ; 
            hare = hare -> next -> next ; 
            tortoise = tortoise -> next ; 
        }
        printf("No cycle detected \n") ; 
}




int main() {
    int n  ;
    scanf("%d", &n);
    int cycle ; 
    printf("Do you want to create a cycle 1 is Yes , 0 is No : \n") ; 
    scanf("%d" , &cycle) ; 

    createLinkedList(n,cycle);
    floydCycleDetection() ; 
    
    return 0;
}