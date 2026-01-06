#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

struct node * A[256] = {NULL} ; 

int max(int x , int y) {
        int result = (x > y) ? x : y ; 
        return result ; 
}
struct node {
    int value ; 
    int visited ; 
    struct node * next ; 
} ; 

int hash(int key){
        int rawHash = 0 , finalHash = 0 ; // eg - for 57 key will will be 12  
        while(key || rawHash > 256){
            if(key != 0) {
            rawHash += key % 10 ; 
            key /= 10 ;
            }
            else{
               int i = 0 ; 
               for(int i = 0 ; i < 2 ; ++i){
                    finalHash += rawHash % 10 ; 
                    rawHash /= 10 ; 
               }
            }   
        } 
        return finalHash ; 
}


void find(int value , int index , int * found ){
        // at that index we find the value
        struct node * curr = A[index] ; 

        while(curr){
                if(curr -> value == value && curr -> visited == 1) {
                    // value is found make *found = 1 
                    *found = 1 ; 
                    return ;   
                } 
                curr = curr -> next ; 
        }
        *found = 0 ; 
        return ; 
}

void insert(int value , int index ) {
        struct node * curr = A[index] ; 

        while(curr){
                if(curr -> value == value){
                        if(curr -> visited == 0) {
                                curr -> visited = 1 ; 
                                return ; 
                        }
                }
                curr = curr -> next ; 
        }
        // Creating a new node 
        struct node * new = (struct node *) malloc(sizeof(struct node)) ; 
        new -> value = value ;
        new -> visited = 1 ; 
        new -> next = A[index] ; 
        A[index] = new ; 
}

void doUnvisit(int hash , int value  ){
        struct node * curr = A[hash] ; 
        while(curr){
            if(curr -> value == value) {
                    curr -> visited = 0 ; 
                    return ; 
            }
            curr = curr -> next ; 
        }
}


int longestContiguousArray(int X[] , int n , int k ) {
        int l = 0 , r = 0 , count = 0 , maxL = INT_MIN , found ;
        while(r != n){
            int index = hash(X[r]) ; 
            find(X[r] , index , &found ) ; 
        
            if (found == 0) {
                insert(X[r] , index) ; 
                count += 1 ; 
                if (count > maxL && count <= k) {
                    maxL = count ; 
                    if (maxL == k) {
                        return k ; 
                    }
                }
                r += 1 ; 
            } 

            else{
                while(found){
                        int leftWindowIndex = hash(X[l]) ; 
                        doUnvisit(leftWindowIndex , X[l]) ; 
                        l += 1 ; 
                        find(X[r] , index , &found) ; 
                        count -= 1 ;
                }
                count += 1 ;
                insert(X[r] , index) ; 
                r += 1 ; 
            }

        }

        return maxL ; 
}


int main(){
        int t ;
        printf("Enter the no of time you want to run the program : \n") ; 
        scanf("%d" , &t) ; 
        
        while(t--){ 
             memset(A , 0 , sizeof(A)) ; 
             int X [100000] ; 
             int n , temp , k;

             printf("Enter k : \n") ;
             scanf("%d" , &k) ;   

             
             printf("Enter the no of element's \n") ;
             scanf("%d" , &n) ; 

             printf("Enter : \n") ; 
             for(int i = 0 ; i < n ; ++i) {
                scanf("%d" , &temp) ; 
                X[i] = temp ; 
             }


            int ans = longestContiguousArray(X , n , k) ; 
            printf("Longest is of length %d \n" , ans) ; 


        }

        return 0 ; 
}


