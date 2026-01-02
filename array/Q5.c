// No of subArray exists in the Array , condition will be S < k 

#include <stdio.h> 

int A[100000] ; 

int noOfSubArray(int A[] , int n , int k ){
    int l = 0 , sum = 0 , count = 0 ;

    for(int r = 0 ; r < n ; ++r) {
            sum += A[r] ; 

            while(sum > k) {
                sum -= A[l] ; 
                l++ ; 
            }

            count += r - l + 1 ;
    }

    return count ; 

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

    int nSa = noOfSubArray(A , n , k) ; 



    printf("noOfSubArrays are %d \n" ,nSa) ; 



    return 0 ;
}