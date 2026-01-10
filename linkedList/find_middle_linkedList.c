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

void createLinkedList(int n) {
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
}


void findMiddle(){
    if (head == NULL) {
        printf("List is empty \n") ; 
        return ; 
    }

    struct node * tortoise = head , *hare = head ; 
    
    while(hare -> next && hare) {
        tortoise = tortoise -> next ; 
        hare = hare -> next -> next ; 
    }
    printf("Middle element is %d \n" , tortoise -> data) ; 
    


}

void freeMemory(){
    struct node * temp ; 

    while(head){
        temp = head ; 
        head = head -> next ; 
        free(temp) ; 
    }
    printf("Memory Freed \n") ; 
}


int main() {
    int n;
    scanf("%d", &n);
    createLinkedList(n);
    findMiddle() ;
    freeMemory() ; 
    return 0;
}


