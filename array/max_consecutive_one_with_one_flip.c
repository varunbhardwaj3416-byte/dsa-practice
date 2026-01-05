/*
Problem:
Given a binary array consisting of only 0s and 1s,
you are allowed to flip at most one 0 to 1.
After the flip, find the maximum number of consecutive 1s
that can be obtained.

Input:
n = number of elements
arr = binary array (containing only 0 and 1)

Output:
Maximum length of consecutive 1s after flipping at most one 0.

Example:
Input:
arr = 1 0 1 1 0

Output:
4

Explanation:
By flipping the zero at index 1, the array becomes:
1 1 1 1 0
which contains 4 consecutive 1s.

Approach (Sliding Window):
- Use two pointers (left and right) to maintain a window.
- Keep a count of zeros in the current window.
- Expand the right pointer.
- If the number of zeros exceeds 1, shrink the window
  from the left until the window contains at most one zero.
- Track the maximum window size during the process.

Time Complexity: O(n)
Space Complexity: O(1)
*/

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