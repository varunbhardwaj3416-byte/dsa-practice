#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head1 = NULL , *head2 = NULL ;

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

        if (head1 == NULL) {
            head1 = newNode(x);
            curr = head1;
        } else {
            curr->next = newNode(x);
            curr = curr->next;
        }
    }
}


void checkPalindrome(){
    // first find middle element of a list

    struct node * tortoise = head1 , *hare = head1 ; 


    while(hare && hare -> next) {
        tortoise = tortoise -> next ; 
        hare = hare -> next -> next ; 
    }

    // reverse from tortoise 
    struct node * head2 = tortoise , *prev = NULL , *next = NULL ; 
    while(head2){
        next = head2 -> next ; 
        head2 -> next = prev ; 
        prev = head2 ; 
        head2 = next ; 
    }
    head2 = prev ; 

    // reading the list from reverse 
    struct node * curr1 = head1 , *curr2 = head2 ; 
    int isPalindrome = 1 ; 
    while(curr2){
        if(curr1 -> data == curr2 -> data) {
            curr1 = curr1 -> next ;
            curr2 = curr2 -> next ; 
        }
        else {
            isPalindrome = 0 ; 
            break ; 
        }  
    }
    if(isPalindrome) printf("It is palindrome \n") ; 
    else printf("Not palindrome \n") ; 
    return ; 


}
void freeMemory(){
   struct node * temp ;
   while(head1 && head1 -> next != NULL ){
     temp = head1 ;
     head1 = head1 -> next ;
     free(temp) ;
   }
   printf("Memory Freed for first list \n") ;

   while(head2){
     temp = head2 ;
     head2 = head2 -> next ;
     free(temp) ;
   }
   printf("Memory Freed for second list \n") ;


}




int main() {
    int n;
    scanf("%d", &n);
    createLinkedList(n);
    checkPalindrome() ;
    freeMemory() ;  
    return 0;
}