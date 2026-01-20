#include <stdio.h>
#include <stdlib.h>
#define totalSize 99999
/*
Invariant:
0 <= base1 <= front1 < base2 <= front2 < base3 <= front3 < totalSize
sizeX = frontX - baseX + 1 (when baseX != -1)
*/

struct threeStack{
    int * stack ; // stack which will contain 3 stacks
    int base1 , front1 ; 
    int base2 , front2 ; 
    int base3 , front3 ; 
    int size1 , size2 , size3 ; // for each stack , size is defined 
    // all the bases used here will be helpful when expanding and shrinking other stacks 
} ;
int capacity(struct threeStack * threeStack , int stackNo) {
    if (stackNo == 1) return threeStack -> base2 ; 
    if (stackNo == 2) return threeStack -> base3 - threeStack -> base2 ; 
    if (stackNo == 3) return totalSize - threeStack -> base3 ; 
    return 0 ; 
} 

struct threeStack * createStack(int size) {
    struct threeStack * new = (struct threeStack *) malloc(sizeof(struct threeStack)) ; 
    if (!new){
        printf("Heap is full , got this when allocating memory for Stack . Try again \n") ; 
        return NULL ; 
    }
    new -> stack = (int*) malloc(sizeof(int) * size) ; 
    if (!new -> stack) {
        printf("Heap is full , got this in allocating size for mainStack not struct stack . Try again \n") ; 
        return NULL ; 
    }
    new -> size1 = new -> size2 = new -> size3 = 0 ; 
    new -> base1 = new -> front1 = new -> base2 = new -> front2 = new -> base3 = new -> front3 = -1 ; 
    return new ;
}
// reminder for push when stack is full write the condition , also for shrinking and expaning 
int expandStack(struct threeStack * , int) ;  
void pushFirstStack(struct threeStack * threeStack , int element) {
    if (!threeStack) {
        return ; // When Null Pointer passed 
    }
    if (threeStack -> size1 == capacity(threeStack , 1)) {
        // expand this first stack 
        int check = expandStack(threeStack , 1) ; // arguments passed is stack no to be expanded , check = can be expanded? or not
        if (!check){
            // can't be pushed , can't readjust any stack to make space for respective stack 
            printf("Stack is full\n") ; 
            return ; 
        } 
        // else continue 
    }
    if (threeStack -> base1 == -1) {
        threeStack -> base1 = 0 ; 
    }
    threeStack -> stack[++threeStack -> front1] = element ; 
    threeStack -> size1 += 1 ; 
    printf("Element pushed Onto First Stack.\nIndex : %d | Value : %d\n\n" , threeStack -> size1 - 1 , element) ; 
}
void pushSecondStack(struct threeStack * threeStack , int element) {
    if (!threeStack) return ; 
    if(threeStack -> size2 == capacity(threeStack , 2 )) {
        expandStack(threeStack , 2) ;   
    }
    if (threeStack -> base2 == -1){ // checking whether any push opn happened 
        threeStack -> base2 = threeStack -> size1 ; 
        threeStack -> front2 = threeStack -> base2 - 1 ; 
    } 
    threeStack -> stack[++threeStack -> front2] = element ; // pushing 
    threeStack -> size2 += 1 ; 
    printf("Element Pushed Onto Second Stack\nIndex : %d | Value : %d\n\n" , threeStack -> size2 - 1 , element) ; 
}
void pushThirdStack(struct threeStack * threeStack , int element) {
    if (!threeStack) return ; 
    if(threeStack -> size3 == capacity(threeStack , 3)) {
        expandStack(threeStack , 3) ; 
    }
    if (threeStack -> base3 == -1){
        threeStack -> base3 = threeStack -> size2 ; 
        threeStack -> front3 = threeStack -> base3 - 1 ; 
    } 
    threeStack -> stack[++threeStack -> front3] = element ; 
    threeStack -> size3 += 1 ; 
    printf("Element Pushed Onto Third Stack\nIndex : %d | Value : %d\n\n" , threeStack -> size3 - 1 , element) ; 
}

int isEmptyFirstStack(struct threeStack * threeStack) { 
    if (threeStack -> size1 == 0) return 1 ; 
    return 0 ; 

}
int isEmptySecondStack(struct threeStack * threeStack) { 
    if (threeStack -> size2 == 0) return 1 ; 
    return 0 ; 
}
int isEmptyThirdStack(struct threeStack * threeStack) { 
    if (threeStack -> size3 == 0) return 1 ; 
    return 0 ; 
}
// write for pop 
void popFirst (struct threeStack * threeStack , int * data , int * found) {
    if (!threeStack || threeStack -> size1 == 0){
        *found = 0 ; 
        return ; 
    }
    if (!data || !found) {
        return ; // assumed if user passed NULL so to catch that used this condition
    }
    *found = 1 ; 
    *data = threeStack -> stack [threeStack -> front1--] ; 
    threeStack -> size1 -= 1 ; 
}
void popSecond (struct threeStack * threeStack , int * data , int * found) {
    if (!threeStack || threeStack -> size2 == 0){
        *found = 0 ; 
        return ; 
    }
    *found = 1 ; 
    *data = threeStack -> stack [threeStack -> front2--] ; 
    threeStack -> size2 -= 1 ; 
}
void popThird(struct threeStack * threeStack , int * data , int * found) {
    if (!threeStack || threeStack -> size3 == 0) {
        *found = 0 ; 
        return ; 
    }
    *found = 1 ; 
    *data = threeStack -> stack[threeStack -> front3--] ; 
    threeStack -> size3 -= 1 ; 
}

int isFull(struct threeStack * threeStack , int stackNo) {
    if (stackNo == 1) {
        return (threeStack -> size1 == capacity(threeStack , 1)) ; 
    }
    if (stackNo == 2) {
        return (threeStack -> size2 == capacity(threeStack , 2 )) ;
    }
    if (stackNo == 3) {
        return (threeStack -> size3 == capacity(threeStack , 3 )) ; 
    }
    return 0 ; 
}
void shiftSecond(struct threeStack *) ; 
void shiftThird(struct threeStack *) ; 
void shrinkFirst(struct threeStack *) ; 
void shrinkSecond(struct threeStack *) ;

int expandStack (struct threeStack * threeStack , int stackNo) {
    if (stackNo == 1) {
        if(threeStack -> size2 == capacity(threeStack , 1 ) && threeStack -> size3 == capacity(threeStack , 3 )) {
            // both stack's are full . Can't do push 
            return 0 ; 
        }
        else if (threeStack -> size2 < capacity(threeStack , 2 )) {
            // shift second stack 
            shiftSecond(threeStack) ; // this will handle new capacity of s1  
            return 1 ; 
        }
        else {
            // second stack is full , try to shift third stack 
            if (threeStack -> size3 < capacity(threeStack , 3)) {
                shiftThird(threeStack) ; // shift stack 2 elements from base3 - 1 
                shiftSecond(threeStack) ; // second stack shifting gives space to stack 1 
                return 1 ; 
            }

        }
    }
    if (stackNo == 2) {
        if (threeStack -> size1 == capacity(threeStack , 1 ) && threeStack -> size3 == capacity(threeStack , 3)) {
            return 0 ; // cant expand 
        }
        if (threeStack -> size3 < capacity(threeStack , 3)){
            // shift 3rd stack 
            shiftThird(threeStack) ; // make sure to change second stack size 
            return 1 ;
        }
        if (threeStack -> size1 < capacity(threeStack , 1 )) {
            // shrink stack 1 
            shrinkFirst(threeStack) ; // copy the second stack elements to new base and fill the second stack 
            return 1 ;                
        }
    }
    if (stackNo == 3) {
        if (threeStack -> size1 == capacity(threeStack , 1 ) && threeStack -> size2 == capacity(threeStack , 2 )) {
            return 0 ; // cant expand 
        }
        if (threeStack -> size2 < capacity(threeStack , 2 )) {
            shrinkSecond(threeStack) ;  // copy the 3rd stack elements to second stack new base and new front 
            // new base and front will point to ; base will point to cap1 + cap2  of second and front just -1 of base  
            return 1 ; 
        }  
        if (threeStack -> size1 < capacity(threeStack , 1)){
            // shrink first then copy content of stack 2 . stack2 capacity will change 
            // then shrink second to make space for stack 3 
            shrinkFirst(threeStack) ; 
            shrinkSecond(threeStack) ;  
            return 1 ; 
        }
    }
    return 0 ;   
}

void shrinkFirst(struct threeStack * threeStack) {
    if (!threeStack) return ; 
    // copy second stack data . Update it's capacity too 
    int tempFront = threeStack -> front1 ; 
    int newBase = tempFront + 1 ; 
    while (threeStack -> base2 <= threeStack -> front2) {
        threeStack -> stack[++tempFront] = threeStack -> stack[threeStack -> base2++] ; 
    }
    threeStack -> base2 = newBase ; 
    threeStack -> front2 = tempFront ; 
    // second stack capacity increased 
}
void shrinkSecond(struct threeStack * threeStack) {
    if (!threeStack) return ; 
    // so we shrink second and then we copy third stack data 
    int newFront = threeStack -> front2 ; 
    int newBase = newFront + 1 ; 
    while (threeStack -> base3 <= threeStack -> front3) {
        threeStack -> stack[++newFront] = threeStack -> stack[threeStack -> base3++] ; 
    }
    threeStack -> base3 = newBase ; 
    threeStack -> front3 = newFront ; 
    // third stack expanded
}
void shiftSecond(struct threeStack * threeStack ) {
    if(!threeStack) return ; 
    // shift second 
    int newBase = threeStack -> base3 ; 
    int newFront = threeStack -> base3 - 1 ; 
    while(threeStack -> front2 >= threeStack -> base2) {
        threeStack -> stack [--newBase] = threeStack -> stack[threeStack -> front2--] ; 
    }
    threeStack -> base2 = newBase ; 
    threeStack -> front2 = newFront ; 
}
void shiftThird(struct threeStack * threeStack) {
    if (!threeStack) return ; 
    int newFront = totalSize - 1 ; 
    
    int newBase = newFront + 1 ; 
    while (threeStack -> front3 >= threeStack -> base3) {
        threeStack -> stack [--newBase] = threeStack -> stack [threeStack -> front3--] ; 
    }
    threeStack -> base3 = newBase ; 
    threeStack -> front3 = newFront ; 
    // change the size of stack 2 
}
void freeThreeStack(struct threeStack * threeStack) {
    if (!threeStack) return ; 
    free(threeStack -> stack) ; 
    free(threeStack) ; 
    printf("Memory Freed\n") ; 
}
void display(struct threeStack * threeStack , int stackNo) {
    if (!threeStack) return ; 
    if (stackNo == 1) {
        if (isEmptyFirstStack(threeStack)) {
            printf("Stack 1 is Empty \n") ; 
        }
        else {
            // display from respective bottom to top of stack 
            int tempFront = threeStack -> front1 ; 
            while(tempFront >= threeStack -> base1) {
                // print
                printf("Index : %d | Value : %d\n" , tempFront , threeStack -> stack [tempFront]) ; 
                tempFront -= 1 ; 
            }
        }
    }
    else if (stackNo == 2 ) {
            if (isEmptySecondStack(threeStack)) {
            printf("Stack 2 is Empty \n") ; 
        }
        else {
            // display from respective bottom to top of stack 
            int tempFront = threeStack -> front2 ; 
            while(tempFront >= threeStack -> base2) {
                // print
                printf("Index : %d | Value : %d\n" , tempFront , threeStack -> stack [tempFront]) ; 
                tempFront -= 1 ; 
            }
        }
    }
    else if (stackNo == 3) {
            if (isEmptyThirdStack(threeStack)) {
            printf("Stack 3 is Empty \n") ; 
        }
        else {
            // display from respective bottom to top of stack 
            int tempFront = threeStack -> front3 ; 
            while(tempFront >= threeStack -> base3) {
                // print
                printf("Index : %d | Value : %d\n" , tempFront , threeStack -> stack [tempFront]) ; 
                tempFront -= 1 ; 
            }
        }
    }
}
int main() {
    int t ; 
    scanf("%d" , &t) ; 
    while(t--) {
        struct threeStack * threeStack = createStack(99999) ;
        while(1){
        printf("1.Enter 1 for Push operation in respective stack\n") ; 
        printf("2.Enter 2 for Pop operation in respective stack\n") ;
        printf("3.Enter 3 for display of respective stacks\n") ; 
        printf("4.Enter 4 for EXIT\n") ; 
        int choice , stackNo ; 
        scanf("%d" , &choice) ; 
        if (choice == 4) break ; 
        switch(choice) {
            case 1 : 
                printf("1.Enter 1 for push in Stack 1\n") ; 
                printf("2.Enter 2 for push in Stack 2\n") ; 
                printf("3.Enter 3 for push in Stack 3\n") ;
                scanf("%d" , &stackNo) ; 
                int element ; 
                if (stackNo == 1) {
                    // push in stack 1 
                    printf("Enter the element : ") ; 
                    scanf("%d" ,&element) ;  
                    pushFirstStack(threeStack , element) ; 
                } 
                else if (stackNo == 2) {
                    printf("Enter the element : ") ; 
                    scanf("%d" , &element) ; 
                    pushSecondStack(threeStack , element) ; 
                }
                else if (stackNo == 3) {
                    printf("Enter the element : ") ; 
                    scanf("%d" , &element) ; 
                    pushThirdStack(threeStack , element) ; 
                }
                else {
                    // don't do anything 
                }
                break ; 
            case 2 : 
                printf("1.Enter 1 to do Pop on Stack 1\n") ; 
                printf("2.Enter 2 to do Pop on Stack2 \n") ; 
                printf("3 Enter 3 to do Pop on Stack3 \n") ; 
                scanf("%d" , &stackNo) ; 
                int data , found ; 
                if (stackNo == 1) {
                    popFirst(threeStack , &data , &found) ;
                    if (found) {
                        printf("Popped element from Stack 1 is %d\n" , data) ; 
                    }
                    else {
                        printf("Stack 1 is empty \n") ;
                    }
                }
                else if (stackNo == 2) {
                    popSecond(threeStack , &data , &found) ; 
                    if (found) {
                        printf("Popped element from Stack 2 is %d\n" , data) ; 
                    }
                    else {
                        printf("Stack 2 is empty \n") ; 
                    }
                }
                else if (stackNo == 3) {
                    popThird(threeStack , &data , &found) ; 
                    if (found) {
                        printf("Popped element from Stack 3 is %d\n" , data) ; 
                    }
                    else {
                        printf("Stack 3 is empty\n") ; 
                    }
                 }
                 else {
                    // stackNo is not entered right ; continue 
                 }
                 break ; 
            case 3 : 
                 printf("1.Enter 1 to display Stack 1\n") ; 
                 printf("2.Enter 2 to display Stack2\n") ; 
                 printf("3.Enter 3 to display Stack3\n") ; 
                 scanf("%d" , &stackNo) ; 
                 if (stackNo == 1) {
                    display(threeStack , 1) ; 
                 }
                 else if (stackNo == 2) {
                    display(threeStack , 2) ; 
                 }
                 else if (stackNo == 3) {
                    display(threeStack , 3) ; 
                 }
                 else {
                    // pass
                 }
                 break ;
             
            default : 
                 printf("Wrong choice entered \n") ; 
                 break ;   
        }
    } 
    // set all stacks to their default state 
    freeThreeStack(threeStack) ; 
    }
    // free the memory 
    // program over

    return 0;
}