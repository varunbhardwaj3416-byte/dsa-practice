/* Question is given a list a1 , a2 ... an - 1 , an . Reorder it to a1 , an , a2 , an-1 , a3 , an-2 ...
without using extra space */


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

void firstLastPair() {
    if (head == NULL) return ; 

    struct node * tortoise = head , *hare = head ; 

    while(hare && hare -> next){
        tortoise = tortoise -> next ; 
        hare = hare -> next -> next ; 
    }
    printf("!\n") ; 

    // reverse from mid onwards 

    struct node * prev = NULL , *curr = tortoise , *next1 = NULL , *next2 = NULL ; 

    while(curr){
        next1 = curr -> next ; 
        curr -> next = prev ; 
        prev = curr ; 
        curr = next1 ; 
    }

    curr = head ; 
    printf("1\n") ; 
    while(prev){
        next2 = prev -> next ; 
        next1 = curr -> next ; 
        curr -> next = prev ; 
        prev -> next = next1 ; 
        prev = next2 ; 
        curr = curr -> next -> next ; 
        if (curr -> next == prev || curr == prev) break ;   
    
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
    firstLastPair() ; 
    displayLinkedList() ; 
    freeMemory() ; 
    return 0;
}