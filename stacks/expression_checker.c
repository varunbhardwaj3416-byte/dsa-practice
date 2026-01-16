#include <stdio.h>
#include <ctype.h>

char stack[100000] ; 
int topIndex = -1 ; 

char top() {
    if (topIndex == -1) return '\0' ; 
    return stack[topIndex] ;  
}

void push(char x ){
    if (topIndex == 99999) return ; 
    stack[++topIndex] = x ;
}

char pop () {
    if (topIndex == -1) return ' ' ; 
    return stack[topIndex--] ; 
 }
 
 int isEmpty(){
    if (topIndex == -1) return 1 ; 
    return 0 ;
}

int isOperator(char x){
    if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^' || x == '%') return 1 ; 
    return 0 ; 
}

void paranthesisChecker(char exp []) {
    if (*exp == '\0'){
        printf("Empty string entered \n") ; 
        return ; 
    }

    // traverse the string from left to right 
    // if '(' encountered then push , if ')' then check the top of the stack if '(' present pop this and continue 
    // at last if expression is valid the stack should be empty 
    int l = 0 , valid = 1 ;  
    while(exp[l]) {
        if (exp[l] == '(') {
            push(exp[l++]) ; 
        }
        else if (exp[l] == ')') {
            if (top() == '(') {
                pop() ; 
                l += 1 ;
             }
             else {
                valid = 0 ; 
                break ; 
             }
        }
        else {
            l += 1 ; 
        }

    }
    if (!valid){
        printf("Not valid string\n") ; 
        
    }
    else if (isEmpty()) {
        printf("String is valid \n") ; 
    }
    else {
        // stack not empty 
        printf("%d\n" , topIndex) ; 
        printf("Not valid expression \n") ; 
    }

}

int main() {
    int t ; 
    printf("Enter the time you want to run the program : ") ; 
    printf("\n") ; 
    scanf("%d" , &t) ; 
    while(t--){
        char exp[100000] ;
        printf("Enter the expression : ") ;
        printf("\n") ;   
        scanf("%s" , &exp) ; 
        paranthesisChecker(exp) ; 
    }
    return 0;
}