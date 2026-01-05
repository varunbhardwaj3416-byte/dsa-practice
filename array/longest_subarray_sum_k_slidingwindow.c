/*
Problem:
Given an array of non-negative integers and an integer K,
find the length of the longest contiguous subarray
whose sum is exactly K.

Input:
n = number of elements
arr = array of non-negative integers
k = target sum

Output:
Length of the longest subarray with sum K.

Example:
Input:
n = 5, k = 5
arr = 1 2 3 2 1

Output:
2   (subarray: 2 3)

Approach (Sliding Window / Two Pointers):
- Use two pointers (left and right) to maintain a window.
- Expand the right pointer to increase sum.
- Shrink the left pointer when sum exceeds K.
- Track the maximum window size when sum equals K.

Note:
This approach works only for non-negative integers.

Time Complexity: O(n)
Space Complexity: O(1)
*/

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