/*
Problem:
Given a string, find the length of the longest substring
without repeating characters.

Input:
str = input string

Output:
Length of the longest substring with all unique characters.

Example:
Input:
"abcabcbb"

Output:
3

Explanation:
The longest substring without repeating characters is "abc".

Approach (Sliding Window + Frequency Array):
- Use two pointers (left and right) to maintain a window.
- Maintain a frequency array (or map) for characters.
- Expand the right pointer while characters are unique.
- Shrink the left pointer when a duplicate is found.
- Track the maximum window size.

Time Complexity: O(n)
Space Complexity: O(1)   (for fixed character set like ASCII)
*/


#include <stdio.h>
#include <limits.h>
#include <string.h> 




int max(int x , int y){
        int L = (x > y) ? x : y ; 
        return L ; 
}

int longestSubstring(char str[] ) {
    int A[256] = {0} ; 
    int length = 0 , l = 0 , r = 0 , maxL = 0 , count = 0 , i = 0 ; // maxL for tracking current maximum length
                                                                // count also used for tracking current length
    char result [1000] ; 

    while(str[r] != '\n') {
            if(A[str[r]] == 0) {
                    // visit it 
                    A[str[r]] = 1 ; 
                    count += 1 ; 
                    if (count > maxL) {
                        // copy from i to r ; 
                        int j = i , k = 0 ; 
                        while(j <= r) {
                                result[k++] = str[j++] ; 
                                 
                        }
                        result[k] ='\0' ; 
                    }
                    r += 1 ; 
                    maxL = max(maxL , count) ;  
            }

            else{
                    while(A[str[r]] == 1) {
                        A[str[l]] = 0 ; 
                        l += 1 ; 
                        count -= 1 ; 
                    }
                    A[str[r]] = 1 ; 
                    i = l ;  
                    count += 1 ; 
                    r += 1 ; 
            }
    }

    printf("Largest Substring is %s with length of %d \n" , result , maxL) ; 

}



int main (){
        int t ; 
        scanf("%d" , &t) ; 
        getchar() ; 

        while(t--){
        printf("Enter the string : \n") ; 
        char str[1000] ; 
        fgets(str , 1000 , stdin) ; 
        longestSubstring(str) ; 
        }

    return 0 ;
}