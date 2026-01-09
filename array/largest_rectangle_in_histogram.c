


#include <stdio.h>
#include <limits.h> 

int max(int x , int y){
        int L = (x > y) ? x : y ;  
        return L ;  
}

int stack[100000] ;
int top = -1 ; // counter for stack top 

void push(int i){
    stack[++top] = i ; 
}

int topStack(){ // value  at top of the stack 
    if (top == -1) return -1 ; 
    return stack[top] ; 
}

int pop(){
    if (top == -1) return -1 ; 
    return stack[top--] ; 
}




int largestRectangleInHistogram(int A[] , int n ) {
    int maxA = 0 ; 
    for (int i = 0 ; i < n ; ++i) {
        if(topStack() == -1) push(i) ; 

        else if(A[i] < A[topStack()]) {
            while(A[topStack()] > A[i] && top != -1) {
                int height = A[pop()] ; 
                int width = i - topStack() - 1 ; 
                int area = height * width ; 
                maxA = max(maxA , area) ; 
            }
            push(i) ; 
        }

        else {
            push(i) ; 
        }
    }

    // emptying the stack 

    while(top != -1 ){
        int rightMostIndex = n ;
        int height = A[pop()] ; 
        int leftMostIndex = topStack() ; 
        int area = height * (rightMostIndex - leftMostIndex - 1) ; 
        maxA = max(maxA , area) ;  

    }
    return maxA ; 


}

int main() {
    printf("Enter the no of time you want to run this program : \n") ; 
    int t , n ; 
    scanf("%d" , &t) ; 

    int arr[10000] ; 

    while(t--){
        printf("Enter no of elements : \n") ;
        scanf("%d" , &n) ;

        for(int i = 0 ; i < n ; ++i) {
            scanf("%d" , &arr[i]) ; 
        }

        printf("Largest rectangle with area is : %d \n" , largestRectangleInHistogram(arr , n) ) ; 
        top = -1 ; 
    }


    return 0;
}



