#include <stdio.h>
#include "circular_queue.h"

void maximum_sum_in_sliding_window(circular_queue * q , int w) {
    if(!q || w == 0) return  ; 
    int B[q -> size - (w - 1)] , j = -1 ; 

    int l = 0 , r = w - 1 ; 
    while(r != q -> size) {
        // find max in the window 
        // and put it in Array B
        int max = q -> queue[l] ; 
        for(int i = l ; i <= r ; ++i) {
            if(q -> queue[i] > max) {
                max = q -> queue[i] ;
            }
        }
        B[++j] = max ; 
        // shift the window 
        l += 1 ; 
        r += 1 ; 
    }
    // print B[]
    for (int i = 0 ; i <= j ; ++i){
        printf("%d\n" , B[i]) ; 
    }
}



int main() {
    int t ; 
    scanf("%d" , &t) ; 
    while(t--) {
        printf("Enter the no of elements in queue\n") ; 
        int n; 
        scanf("%d" , &n) ; 
        circular_queue * q = createCircularQueue(n) ; 
        // made queue with n size 
        for(int i = 0 ; i < n ; ++i) {
            printf("Enter \n") ; 
            int element ; 
            scanf("%d" , &element) ; 
            enQueue(q , element) ; 
        }
        int w ; 
        printf("Enter the window size\n") ; 
        scanf("%d" , &w) ;
        maximum_sum_in_sliding_window(q , w) ; 
        freeQueue(q) ; 
    }

    return 0;
}