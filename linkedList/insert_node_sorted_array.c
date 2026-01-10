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


void insertNode(int value){

    struct node * prev = NULL , *curr = head ; 

    while(curr){
        if(value < curr -> data) {
          if(prev){
            prev -> next = newNode(value) ; 
            prev -> next -> next = curr ; 
            return ; 
          }
          head = newNode(value) ; 
          head -> next = curr ; 
          return ; 
        }
        prev = curr ; 
        curr = curr -> next ; 
    }
    prev -> next = newNode(value) ; 
    prev -> next -> next = NULL ; 

}

void displayLinkedList() {

    struct node * curr = head ; 
    while(curr) {
        printf("%d -> " , curr -> data) ; 
        curr = curr -> next ; 
    }
    printf("NULL \n") ; 
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
    scanf("%d" , &n) ; 
    insertNode(n) ; 
    displayLinkedList() ; 
    freeMemory() ; 
    return 0;
}