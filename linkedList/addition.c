#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head1 = NULL , *head2 = NULL , *head3 = NULL ; // head3 for resultant addition of two list's 



struct node* newNode(int value) {
    struct node *n = (struct node*)malloc(sizeof(struct node));
    n->data = value;
    n->next = NULL;
    return n;
}

struct node *createLinkedList(int n) {
    int x;
    struct node *curr = NULL , *head = NULL ;

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
    return head ; 
}

struct node * attach(int sum ){
    if (sum == 0) return NULL ; 
    struct node * prev = attach(sum / 10) ; 
    if (!prev){
        head3 = newNode(sum % 10) ; 
        prev = head3 ; 
        return prev ;  
    } 
    else {
        prev -> next = newNode(sum % 10 )  ; 
        prev = prev -> next ; 
    }
    return prev ; 
}

void displayLinkedList() {
    struct node *curr = head3;
    printf("Sum is : ") ; 
    while (curr) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}




void addition(){
    int secondNo = 0 , firstNo = 0 ; 
    struct node * curr1 = head1 ; 
    while(curr1){
        firstNo = firstNo * 10 + curr1 -> data ; 
        curr1 = curr1 -> next ;  
    }
    curr1 = head2 ; 
     while(curr1){
        secondNo = secondNo * 10 + curr1 -> data ; 
        curr1 = curr1 -> next ;  
    }
    // now both no's we got add them 
    int sum = firstNo + secondNo ; 

    attach(sum) ; 
    displayLinkedList() ; 
}

int main() {
    int n;
    scanf("%d", &n);
    head1 = createLinkedList(n) ;
    printf("For second list enter the no of digit's : \n") ; 
    scanf("%d" , &n) ; 
    head2 = createLinkedList(n) ;
    addition() ;  
    return 0;
}