
#include <stdio.h>
#include <limits.h>
#include <string.h> 

int A[256] = {0} ; 



int max(int x , int y){
        int L = (x > y) ? x : y ; 
        return L ; 
}

int longestSubstring(char str[]) {
    int length = 0 , l = 0 , r = 0 , maxL = 0 , count = 0 ; 

    while(str[r] != '\n') {
            if(A[str[r]] == 0) {
                    // visit it 
                    A[str[r]] = 1 ; 
                    r += 1 ;
                    count += 1 ; 
                    maxL = max(maxL , count) ; 
                    
            }

            else{
                    while(A[str[r]] == 1) {
                        A[str[l]] = 0 ; 
                        l += 1 ; 
                        count -= 1 ; 
                    
                    }
                    count += 1 ; 
                    r += 1 ; 

            }
    }

    return maxL ; 
}



int main (){
    printf("Enter the string : \n") ; 
    char str[1000] ; 
    fgets(str , 1000 , stdin) ; 


    int lS = longestSubstring(str) ; 


    printf("Longest substring is : %d " , lS) ; 
    
    
    return 0 ;
}