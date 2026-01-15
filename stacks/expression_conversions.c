#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// I've used two stacks one of char type and one of int type char type . 
// char type stack are used in infix to postfix and prefix conversions 
// whereas int stacks are used in computing the values of prefix postfix conversion to their infix value 


char stack[100000] ; 
int secondStack[100000] , secondTop = -1 ; // this is used for prefix and postfix to infix value conversion 
int topIndex = -1 ; // to track stack head 
char result[100000] ; 
int resultIndex = -1 ; 

void reverse (char * exp) {
    if (*exp == '\0') return ; 
    int length = strlen(exp) ; 
    int front = 0 , last = length - 1 ; 
    while(front < last) {
        // swap them 
        int temp = exp[front] ; 
        exp[front] = exp[last] ; 
        exp[last] = temp ; 
        front += 1 ; 
        last -= 1 ; 
    }
}

int precedence(char x) {
    if (x == '^') return 3 ; 
    if (x == '*' || x == '/' || x == '%') return 2 ; 
    else if (x == '+' || x == '-') return 1 ; 
    else if (x == '\0') return 0 ; 
    else return -1 ; 
}

char top (char x) {
    if(topIndex == -1) return '\0'  ; 
    return stack[topIndex] ; 
}

char pop(){
    if (topIndex == -1) return ' ' ; 
    else return stack[topIndex--] ; 
}

int secondStackPop(){
    if (secondTop == -1) return 0 ; 
    return secondStack[secondTop--] ; 
}

int convertOperator(char x , int a , int b ) {
    int result ; 
    if (x == '*'){
        result = a * b ; 
    }  
    if (x == '/'){
        result = a / b  ; 
    } 
    if (x == '-'){
        result = a - b ; 
    }  
    if (x == '+'){
        result = a + b ; 
    } 
    if (x == '^'){
        result = pow(a , b) ;     
    } 
    if (x == '%'){
        result = a % b ; 
    }
    return result ;  
    
    
}

void infixToPostfix(char exp[]) {
    if (*exp == '\0') return ; 
    
    // scan the expression left to right 
    int l = 0 ; 
    while(exp[l]){
        if(isalpha(exp[l]) || isdigit(exp[l])){
            result[++resultIndex] = exp[l++] ; 
        }
        else{
            if (exp[l] == '(') {
                stack[++topIndex] = exp[l++] ; 
            }
            else if (exp[l] == ')') {
                while(topIndex != -1 && stack[topIndex] != '(') {
                    result[++resultIndex] = pop() ; 
                }
                pop() ; 
                l += 1 ; 
            }
            else if(precedence(exp[l]) > precedence(stack[topIndex])) {
                stack[++topIndex] = exp[l++] ; 
            }
            else {
                // precedence is less 
                while(precedence(stack[topIndex]) > precedence(exp[l]) && topIndex != -1){
                    result[++resultIndex] = pop() ; 
                }
                // push exp[l]
                stack[++topIndex] = exp[l++] ; 
            }
        }
    }
    while(topIndex != -1) {
        result[++resultIndex] = stack[topIndex--] ; 
    }
    result[++resultIndex] = '\0' ; 
    printf("Infix to Postfix expression is : %s \n" , result) ; 
    topIndex = -1 ; 
    resultIndex = -1 ;  

}

void infixToPrefix(char exp[]){
    if (*exp == '\0') return ; 
    // reverse the expression ; 
    char rev[100000] ; 
    int length = strlen(exp) ; 
    reverse(exp) ;  

    int l = 0 ; 
    while(exp[l]){
        if ( isalpha(exp[l]) || isdigit(exp[l]) ) {
            result[++resultIndex] = exp[l++] ; 
        }
        else {
            if(exp[l] == ')'){
                stack[++topIndex] = exp[l++] ; 
            }
            else if (exp[l] == '(') {
                // pop until '(' this appears 
                while(topIndex != -1 && stack[topIndex] != ')'){
                    result[++resultIndex] = pop() ; 
                }
                pop() ; // to pop '(' opening bracket 
                l += 1 ;
            }
            else{ 
                if (precedence(exp[l]) > precedence(stack[topIndex])){
                    stack[++topIndex] = exp[l++] ; 
                }
                else {
                    while(topIndex != -1 && precedence(stack[topIndex]) > precedence(exp[l])){
                        result[++resultIndex] = pop() ; 
                    }
                    stack[++topIndex] = exp[l++] ; 
                }
            }
    
        }
    }
    while(topIndex != -1) {
        // copy remaining operators to result 
        result[++resultIndex] = pop() ; 
    }
    // reverse the result 

    result[++resultIndex] = '\0' ; 
    reverse(result) ;  

    // rev is prefix expression 
    printf("Infix to prefix is : %s \n" , result) ; 
    topIndex = -1 ; 
    resultIndex = -1 ; 
}

void postfixToValue(char exp[]){
    // scan the postfix expression 
    int l = 0 ; 
    while(exp[l]){
        if (isdigit(exp[l]) ) {
            // push onto stack 
            int value = (int)exp[l++] - 48 ; 
            secondStack[++secondTop] = value ; 
        }
        else {
            // if operator then pop two time's and store the result in stack[top]
            int a = secondStackPop() ; 
            int b = secondStackPop() ; 
            int result = convertOperator(exp[l++] , a , b) ; 
            secondStack[++secondTop] = result ; 
        }
    }
    printf("Result of Postfix to Infix expression is : %d \n" , secondStack[secondTop]) ; 
    secondTop = -1  ;
}

void prefixToValue(char exp[]) {
    if (*exp == '\0') return ; 
    // traverse prefix expression from reverse 

    int length = strlen(exp) ; 
    int i = length - 1 ; 
    while( i >= 0) {
        if(isdigit(exp[i])) {
            int digit = (int) exp[i] ; 
            digit -= 48 ; 
            secondStack[++secondTop] = digit ; 
            i -= 1 ; 
        }
        else  {
            // it is a operator and the pushed one is already a digit  
            int a = secondStackPop() ;               
            int b = secondStackPop() ; 
            int result = convertOperator(exp[i] , a , b) ; 
            secondStack[++secondTop] = result ; 
            i -= 1 ; 
        } 
    }
    printf("Prefix to Infix result is %d \n" , secondStack[secondTop]) ; 
    secondTop = -1 ; 
}

int main() {
    int t ; 
    scanf("%d" , &t) ; 
    while(t--){
    char expression[100000] ; 
    int choice = -1 ; 
    printf("Enter expression : \n") ; 
    scanf("%s" , &expression) ;
    printf("Enter 1 for infix to Postfix conversion \nEnter 2 for infix to Prefix conversion\nEnter 3 for Postfix to infix\nEnter 4 for Prefix to Infix conversion\nEnter : ") ; 
    printf("\n") ; 
    scanf("%d" , &choice) ; 
    // using switch for case filtering 
    switch (choice) {
        case 1 : 
            infixToPostfix(expression) ; // function will print the final expression 
            topIndex = -1 ; 
            resultIndex = -1 ; 
            break ;                      // same for other function as well 

        case 2 : 
            infixToPrefix(expression) ; 
            topIndex = -1 ; 
            resultIndex = -1 ;
            break ; 

        case 3 : 
            postfixToValue(expression) ;
            topIndex = -1 ; 
            resultIndex = -1 ; 
            break ; 
        case 4 : 
            prefixToValue(expression) ;
            topIndex = -1 ; 
            resultIndex = -1 ; 
            break ; 
        default : 
            printf("Invalid choice entered \n") ; 
            break ; 
    }
    }

    return 0;
}