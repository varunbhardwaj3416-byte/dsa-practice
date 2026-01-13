#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL , *sorted = NULL ;

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


void insertionSort(){
    if (head == NULL) return ; 
    struct node * curr1 = head , *curr2 , *prev = NULL ; 

    while(curr1){
        if(!sorted) {
            sorted = newNode(curr1 -> data) ; 
            curr1 = curr1 -> next ; 
            curr2 = sorted ;  
        } 
        else if (curr1 -> data > curr2 -> data) {
            // insert it to curr2 next ; 
            curr2 -> next = newNode(curr1 -> data) ;
            curr2 = curr2 -> next ; 
            curr1 = curr1 -> next ;   
        } 
        else {
            // if the element is less than sorted list current element find the suitable place 
            struct node * findPos = sorted  ; 
            while(findPos -> data <= curr1 -> data) {
                prev = findPos ; 
                findPos = findPos -> next ; 
            }
            if(!prev){
                sorted = newNode(curr1 -> data) ; 
                sorted -> next = findPos ; 
                curr1 = curr1 -> next ; 
            }
            else{
                prev -> next = newNode(curr1 -> data) ; 
                prev = prev -> next ; 
                prev -> next = findPos ; 
                prev = NULL ; 
                curr1 = curr1 -> next  ; 
            }
        }
    }



}

void displayLinkedList() {
    struct node *curr = sorted;
    while (curr) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

int main() {
    int n;
    scanf("%d", &n);
    createLinkedList(n);
    insertionSort() ; 
    displayLinkedList() ; 

    return 0;
}