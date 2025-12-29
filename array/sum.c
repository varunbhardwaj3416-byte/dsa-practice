#include <stdio.h> 

int sum (int x , int y){ 
	return x + y ; 

}

int main () { 
	int x , y ; 
	printf("Enter the value for x : ") ; 
	scanf("%d" , &x) ; 
	printf("Enter the value for y : ") ; 
	scanf("%d" , &y) ; 

	printf("Sum is %d" , sum(x , y)) ; 

	return 0 ; 

}