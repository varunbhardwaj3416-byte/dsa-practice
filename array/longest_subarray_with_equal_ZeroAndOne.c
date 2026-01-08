/*
 Problem Statement
You are given a binary array arr of size n consisting only of 0s and 1s.
Your task is to find the length of the longest contiguous subarray that contains equal number of 0s and 1s.

Example
Input
arr = [0, 1, 0, 0, 1, 1, 0]

Output
6

Explanation
The subarray from index 1 to 6 → [1, 0, 0, 1, 1, 0]
contains 3 zeros and 3 ones.

1 ≤ n ≤ 10^5

arr[i] ∈ {0, 1}
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 100003 

int A[100000] ; 


int max (int x , int y ) {
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



int subarrayWithEqualZerosAndOne(int A[] , int n ) {
    for(int i = 0 ; i < n ; ++i) {
            if(A[i] == 0) A[i] = -1 ; 
            // converting 0 to -1 , now the sub array which has equal zero and one will have the sum 0 
    }

    int sum = 0 , maxL = 0 ; 

    for(int r = 0 ; r < n ; ++r) {
        sum += A[r] ; 

        if(sum == 0){
            maxL = max(maxL , r + 1) ; 
        }
        else { 
            // checking that we saw the sum earlier 
            int found ; 
            int index = findIndex(sum , &found) ; 

            if (found == 1){
                maxL = max(maxL , r - index) ; 
            }
        }
    }
    return maxL ; 

    
}

int main (){ 
    int t ; 
    printf("Enter the no of time you want to run this : \n") ; 
    scanf("%d" , &t) ; 

    while(t--){
        int n , temp ; 
        printf("Enter the no of element's : \n") ; 
        scanf("%d" , &n) ; 

        for(int i = 0 ; i < n ; ++i) {
            scanf("%d" , &temp) ; 
            A[i] = temp ; 

        }
        int maxLen = subarrayWithEqualZerosAndOne(A , n) ; 

        printf("Maxlen is %d \n" , maxLen) ;
        
        memset(map , 0 , sizeof(map)) ; 

    }


    return 0 ; 
}

