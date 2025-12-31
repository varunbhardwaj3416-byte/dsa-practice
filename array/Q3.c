#include <stdio.h>
#include <stdlib.h>
#define SIZE 100003 

int A[100000] ; 


int MAX (int x , int y ) {
    if(x > y) return x ; 
    else return y ; 
}
struct node {
        int key ;
        int value ;  
        struct node * next ;  
}; 


struct node * map[SIZE] = {NULL} ;

int hash(int key){
        if (key < 0) key = -key ; 
        return key % SIZE ; 
}


void insert(int key , int value){
    int index = hash(key) ; 

    struct node * curr = map[index] ; 

    while(curr){
            if(curr -> key == key) {
                    return ; 
            }
        curr = curr -> next ;
    }
    struct node * new = (struct node *) malloc(sizeof(struct node )) ; 
    new -> key = key ; 
    new -> value = value ; 
    new -> next = map[index] ; 
    map[index] = new ; 
}


int findIndex(int key , int * found){
    int index = hash(key) ; 
    
    struct node * curr = map[index] ; 

    while(curr){
            if (curr -> key == key) {
                *found = 1 ; 
                return curr -> value ; 
            }
        curr = curr -> next ; 
    }
    *found = 0 ; 
    return -1 ;
} 



int longestSubArraySumK(int A[] , int n , int k) {
    int sum = 0 , maxLen = 0 ; 

    for(int i = 0 ; i < n ; ++i) {
        sum += A[i] ; 
        
        if (sum == k) {
                // sub-array is from 0 to i 
                maxLen = MAX(maxLen , i + 1) ; 
        }

        // checking whether we saw sum - k earlier 
        
        int found ; 
        int index = findIndex(sum - k , &found) ; 
        
        if (found == 1) {
                maxLen = MAX(maxLen , i - index) ; 
        }

        insert(sum , i) ; 
    }

    return maxLen ; 

}

int main () {
    int n ; 
    printf("Enter the no of element's : \n") ; 
    scanf("%d" , &n) ; 

    int k ; 
    printf("Enter k : \n") ; 
    scanf("%d" , &k) ; 

    printf("Enter the elements : \n") ; 
    int temp ; 

    for(int i = 0 ; i < n ; ++i) {
        scanf("%d" , &temp) ; 
        A[i] = temp ; 

    }

    int maxLen = longestSubArraySumK(A , n , k) ; 

    printf("Maxlen is %d \n" , maxLen) ; 

    return 0 ; 
}

