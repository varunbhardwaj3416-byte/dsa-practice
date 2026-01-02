
#include <stdio.h>
#include <limits.h>
#include <string.h> 




int max(int x , int y){
        int L = (x > y) ? x : y ; 
        return L ; 
}

int longestSubstring(char str[] ) {
    int A[256] = {0} ; 
    int length = 0 , l = 0 , r = 0 , maxL = 0 , count = 0 , i = 0 ; 

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