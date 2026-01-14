#include <stdio.h>
#include <stdlib.h>
#define TABLESIZE 100001 

struct node * hashTable[10000] = {NULL} ; 

struct node {
    int data;
    struct node *next;
};





int hash(int key){
    if (key < 0) return -key % TABLESIZE ; 
    else return key % TABLESIZE ; 
}


struct node *find(int key) {
    int index = hash(key) ; 
    struct node * curr = hashTable[index] ; 
    while(curr) {
        if (curr -> data == key) {
            return curr ; 
        }
        curr = curr -> next ; 
    }
    return NULL ; 

}

struct node * newNode(int) ; 

void insert(int sum) {
    int index = hash(sum) ; 
    struct node * curr = hashTable[index] ; 
    
    while(curr) {
        if(curr -> data == sum) {
            return ; 
        }
        curr = curr -> next ; 
    }
    struct node * new = newNode(sum) ; 
    new -> next = hashTable[index] ; 
    hashTable[index] = new ; 

}
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
void freeMemory(struct node *) ; 

void deleteConsecutiveNodes() {
    if (head == NULL) return ; 
    int sum = 0 ; 
    struct node * curr = head ; 
    while(curr) {
        sum += curr -> data ; 
        // find sum  
        if (sum == 0) {
            struct node * newHead = curr -> next ; 
            curr -> next = NULL ; 
            freeMemory(head) ; 
            head = newHead ; 
            curr = head ; 
        }
        else {
            struct node * prev = find(sum) ; 
            if(prev) {
                // found the prefix 
                struct node * next2 = curr -> next , *next1 = prev -> next ;
                curr -> next = NULL ; // delete from next1 to curr 
                prev -> next = next2 ; 
                // free memory from next1 to curr 
                freeMemory(next1) ; 
                curr = next2 ; 
            }
            else {
                insert(sum) ; 
                curr = curr -> next ; 
            }
        }   
    }

}
void freeMemory(struct node * head){
   struct node * temp ;
   while(head){
     temp = head ;
     head = head -> next ;
     free(temp) ;
   }
   printf("Memory Freed \n") ;
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
    deleteConsecutiveNodes() ; 
    displayLinkedList() ; 
    freeMemory(head) ; 
    return 0;
}