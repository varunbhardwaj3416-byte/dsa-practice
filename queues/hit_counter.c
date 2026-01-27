#include <stdio.h>
#include "circular_queue.h"

int ping(circular_queue * q , int time) {
    if(!q) return 0 ; 
    // traverse queue and update front if front time is not in the range [t-3000 , t] inclusive
    enQueue(q , time) ; 
    while(q -> queue[q -> front] < time - 3000) {
        q -> front = (q -> front + 1) % (q -> capacity) ; 
        q -> size = q -> size - 1 ; 
    }
    // put t in rear
    if(size(q) == capacity(q)){
        doubleQueue(q) ; 
    } 
    return size(q) ; 
}
void recentCounterClass(circular_queue * q) {
    // initialise counter with zero requests
    // set front and rear to -1 
    q -> front = q -> rear = -1 ; 
}
int displayTime(int t){
    if(t >= 3000) return t - 3000 ; 
    return 0 ;
}
int main() {
    circular_queue * q = createCircularQueue(25) ;
    // set recentCounter to 0 
    recentCounterClass(q) ;  
    int t ; 
    printf("Enter the no of requests you want to put in \n") ; 
    scanf("%d" , &t) ; 
    while(t--) {
        int time ; 
        printf("Enter the time: \n") ; 
        scanf("%d" , &time) ; 
        printf("Recent requests in time frame [%d , %d] is %d\n" , displayTime(time) , time , ping(q , time)) ; 
    }
    freeQueue(q) ; 
    return 0;
}