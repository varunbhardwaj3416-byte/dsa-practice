// Longest sub - array with sum <= k . Non - negative no's in array 

#include <stdio.h>
#include <limits.h>

int A[100000] ; 

int max(int x , int y ){
        int Largest =  (x > y) ? x : y ;
        return Largest ;  
}

int longestSubArrayLessEqual(int A[] , int n , int k){
    int l = 0 , largest = INT_MIN , sum = 0 ;
    
    for(int r = 0 ; r < n ; ++r){
        sum += A[r] ; 

        while(sum > k ) {
                sum -= A[l] ; 
                l++ ; 
        }
        largest = max(largest , r - l + 1) ;  
    }

    return largest ;   
}



int main (){
    int n ; 
    printf("Enter the no of elements : \n") ; 
    scanf("%d" , &n) ; 

    int k , temp ; 
    printf("Enter k : \n") ; 
    scanf("%d" , &k) ; 

    printf("Enter the elements : \n") ; 
    for (int i = 0 ; i < n ; ++i) {
            scanf("%d" , &temp) ; 
            A[i] = temp ; 

    }

    int largestSubArray = longestSubArrayLessEqual(A , n , k) ; 



    printf("Largest subArray Length is %d \n" ,largestSubArray) ; 



    return 0 ;
}