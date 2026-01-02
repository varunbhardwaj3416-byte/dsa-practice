
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