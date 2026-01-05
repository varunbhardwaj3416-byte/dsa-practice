/*
Problem:
Given an array of integers, find the second largest distinct element in the array.

Input:
n = number of elements
arr = array of integers

Output:
The second largest distinct element.
If it does not exist, print an appropriate message.

Example:
Input:
5
1 2 3 4 5

Output:
4

Approach:
Maintain two variables:
- M  = largest element
- sM = second largest element

Traverse the array once and update M and sM accordingly.

Time Complexity: O(n)
Space Complexity: O(1)
*/


#include <stdio.h>
#include <limits.h>

int array[100000] ; 
int main(){
	int n ; 
	printf("Enter the no of element's : \n") ; 
	scanf("%d" , &n) ; 

	int temp ; 
	printf("Enter the elements : \n") ; 

	// For secondMax and Max we use two counters 
	int sM , M ; // M store's max 
	sM = M = INT_MIN ; 

	for(int i = 0 ; i < n ; ++i){ 
		scanf("%d" , &temp) ; 
		array[i] = temp ; 
		if (array[i] > M ){
			sM = M ; 
			M = array[i] ; 		
 		}
		else if (array[i] > sM && array[i] != M) {
			sM = array[i] ; 
		}
	}

	if (sM == -1){ 
		printf("-1 \n") ;
	}
	
	else{
	printf("Second largest element is -> %d \n" , sM) ; 
	} 


	return 0 ; 
}

