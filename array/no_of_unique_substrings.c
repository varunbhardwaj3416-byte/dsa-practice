/*
Problem:
Given a string, count the total number of substrings
that contain all distinct (unique) characters.

A substring is defined by a contiguous sequence of characters
identified by its starting and ending indices.
Substrings with the same characters but different positions
are considered different.

Input:
str = input string

Output:
Total number of substrings having all distinct characters.

Example:
Input:
"aba"

All substrings:
"a"   (index 0)  -> valid
"ab"            -> valid
"aba"           -> invalid (repeated 'a')
"b"   (index 1)  -> valid
"ba"            -> valid
"a"   (index 2)  -> valid

Output:
5

Explanation:
Even though character 'a' appears twice in the string,
the substrings "a" at index 0 and index 2 are counted separately
because they originate from different positions.

Approach (Sliding Window):
- Use two pointers to maintain a window of unique characters.
- Expand the right pointer while characters are unique.
- Shrink the left pointer when a duplicate is encountered.
- For each position, add (right - left + 1) to the count,
  representing all valid substrings ending at that position.

Time Complexity: O(n)
Space Complexity: O(1)   (for fixed character set such as ASCII)
*/

#include <stdio.h>
#include <limits.h>
#include <string.h> 
int max(int x , int y){
        int L = (x > y) ? x : y ; 
        return L ; 
}

int noOfSubstring(char str[]) {
    int A[256] = {0} ; 
    int length = 0 , l = 0 , r = 0 , count = 0 ; 

    while(str[r] != '\n') {
            if(A[str[r]] == 0) {
                    // visit it 
                    A[str[r]] = 1 ; 
                    count += r - l + 1 ; 
                    r += 1 ;   
            }

            else{
                    while(A[str[r]] == 1) {
                        A[str[l]] = 0 ; 
                        l += 1 ; 
                    
                    }
                    A[str[r]] = 1 ; 
                    count += r - l + 1 ; 
                    r += 1 ; 

            }
    }

    return count ; 
}



int main (){
    printf("Enter the string : \n") ; 
    char str[1000] ; 
    fgets(str , 1000 , stdin) ; 


    int lS = noOfSubstring(str) ; 


    printf("No of substring without repeating character are : %d " , lS) ; 
    
    
    return 0 ;
}