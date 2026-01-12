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


void evenOdd(){
    struct node * even = NULL , *odd = NULL , *evenTail = NULL , *oddTail = NULL ; 
    int firstEven = 0 , firstOdd = 0 ; 
    //printf("1\n") ; 
    while (head){
        if(head -> data % 2 == 0 && !firstEven) {
            even = head ; 
            evenTail = head ; 
            firstEven = 1 ; 
            head = head -> next ; 
        }
        else if ((head -> data) % 2 != 0 && !firstOdd) {
            odd = head ; 
            oddTail = head ; 
            firstOdd = 1 ;
            head = head-> next ;  
        }
        else if (head -> data % 2 == 0) {
            evenTail -> next = head ; 
            evenTail = evenTail -> next ; 
            head = head -> next ;   
        }
        else {
            oddTail -> next = head ; 
            oddTail = head ; 
            head = head -> next ; 
        }
    }

    if(even){
        evenTail -> next = odd ;
        head = even ;  
    }
    else if (odd) {
        head = odd ; 
    }
    
}

void displayLinkedList() {
    struct node *curr = head;
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
    evenOdd() ; 
    displayLinkedList() ; 
    return 0;
}