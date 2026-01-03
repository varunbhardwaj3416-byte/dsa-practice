#include <stdio.h>
#include <limits.h>

int max(int x , int y){
        int L = (x > y) ? x : y ; 
        return L ; 
}

int longestBinary(int A[] , int n) {
        int  r = 0 , maxL = INT_MIN , count = 0 , firstZero = 0 ; // firstZero is a flag  


        while(r != n ){
            if(!firstZero || A[r] == 1) {
                if (A[r] == 0) firstZero = 1 ; 
                count += 1 ; 
                maxL = max(maxL , count) ;
                r += 1 ; // r points to next one  
            }
            else if(A[r] == 0) {
                count = 0 ; 
                firstZero = 0 ;  
            }
        }
        return maxL ; 
}


int main(){
        int n , temp; 
       scanf("%d" , &n) ;
       int A[100] ;  

       for(int i = 0 ; i < n ; ++i){
            scanf("%d" , &temp) ; 
            A[i] = temp ; 
       }


       int  ans = longestBinary(A, n)  ; 
        printf("Ans is -> %d\n" , ans) ; 
        return 0 ; 
}