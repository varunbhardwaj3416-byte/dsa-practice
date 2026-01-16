#include <stdio.h>
#include <stdlib.h>


struct node {
    int data ; 
    struct node * next ; 
} ; 


struct node * head = NULL ; 



struct node * newNode(int value) {
    struct node * new = (struct node *) malloc(sizeof(struct node)) ; 
    new -> data = value ; 
    new -> next = NULL ; 
    return new ; 
}



void createLinkedList(int n) {
    if (n == 0) return ; 
    
    int temp ; 
    printf("Enter the elements : \n") ; 
    struct node * curr = NULL , *new ; 
    for (int i = 0 ; i < n ; ++i){
        if (i == 0) {
            scanf("%d" , &temp) ; 
            head = newNode(temp) ;
            curr = head ; 
        }
        else {
            scanf("%d" , &temp) ; 
            new = newNode(temp) ; 
            curr -> next = new ; 
            curr = new ;
        }
        
    }
    curr -> next = NULL  ;


    printf("Linked list created \n") ; 


}



void reverseLinkedList(int n){
    if (n == 0) return ; 

    struct node * prev = NULL , *curr = head , *next = NULL ; 

    while(curr){
        next = curr -> next ; 
        curr -> next = prev ; 
        prev = curr ; 
        curr = next ; 
    }
    head = prev ; 


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
    int t ; 
    printf("Enter the no of time you want to run the program \n") ; 
    scanf("%d" , &t) ;
    
    while(t--){
        printf("Enter the no of elements : \n") ; 
        int n ; 
        scanf("%d" , &n) ; 
        createLinkedList(n) ; 
        reverseLinkedList(n) ; 
        displayLinkedList() ; 
        freeMemory() ;  
    }


    return 0;
}