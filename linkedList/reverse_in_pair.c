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
    if (n == 0) return ; 
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
    curr -> next = NULL ; 
}

void reverseInPair(){
    struct node * first = head ;  

    while(first && first -> next){ 
        int data = first -> data ; 
        first -> data = first -> next -> data ; 
        first -> next -> data = data ; 
        first = first -> next -> next ;
        
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

    reverseInPair() ; 
    displayLinkedList() ; 
    return 0;
}