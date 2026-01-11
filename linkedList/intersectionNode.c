#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head1 = NULL;
struct node *head2 = NULL ; 

struct node* newNode(int value) {
    struct node *n = (struct node*)malloc(sizeof(struct node));
    n->data = value;
    n->next = NULL;
    return n;
}

void createLinkedList(int n) {
    int x;
    struct node *curr1 = NULL;

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);

        if (head1 == NULL) {
            head1 = newNode(x);
            curr1 = head1;
        } else {
            curr1->next = newNode(x);
            curr1 = curr1->next;
        }
    }

    // creating second list for intersection of same length  n - 1 , last node will be intersecting node 

    printf("For second list enter : \n") ; 
    struct node * curr2 = NULL ; 
    for(int i = 0 ; i < n - 1 ; ++i) {
        if (i == 0){
            scanf("%d" , &x) ; 
            head2 = newNode(x) ; 
            curr2 = head2 ; 
        }
        else {
            scanf("%d" , &x) ; 
            curr2 -> next = newNode(x) ;
            curr2 = curr2 -> next ;  
        }
    }
    curr2 -> next = curr1 ; // connecting second list to intersecting node 
    curr1 -> next = NULL ; // setting last intersecting node to NULL . 


}


void findIntersectionNode(){
    struct node *p1 = head1 , *p2 = head2 ; 

    while(p1 != p2){
        p1 = (p1 == NULL)?  head2 : p1 -> next ; 
        p2 = (p2 == NULL)?  head1 : p2 -> next ; 
    }

    if(!p1) printf("No intersection \n") ; 
    else printf("Intersection at node %p address \n" , p1) ; 
}




int main() {
    int n;
    scanf("%d", &n);
    createLinkedList(n);
    findIntersectionNode() ; 
    return 0;
}