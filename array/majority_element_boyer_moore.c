/*
Problem:
Given an array of integers of size n, find the majority element.
A majority element is an element that appears more than ⌊n/2⌋ times.

It is guaranteed that a majority element exists in the array.

Input:
n = number of elements
arr = array of integers

Output:
The majority element.

Example:
Input:
n = 7
arr = 2 2 1 1 1 2 2

Output:
2

Approach (Boyer–Moore Voting Algorithm):
- Maintain a candidate and a counter.
- If counter is 0, choose the current element as candidate.
- Increment counter if current element equals candidate.
- Decrement counter otherwise.
- After one pass, the candidate will be the majority element.

Time Complexity: O(n)
Space Complexity: O(1)
*/


#include <stdio.h> 
#include <math.h> 

int array[100000] ; 
int main (){
	int n ; 
	printf("Enter the no of elements : \n") ; 
	scanf("%d" , &n) ; 
	

	int temp ; 
	printf("Enter : \n") ; 


	for (int i = 0 ; i < n ; ++i) { 
		scanf("%d" , &temp) ; 
		array[i] = temp ; 
	}
	 
	int majority = array[0], count = 0 ; // iajority is our candidate , initially taken to first element
	 
	// using Boyer's Moore voting algorithm 
	for (int i = 0 ; i < n ; ++i) {
		if (majority == array[i]) count++ ; 
		else{
			count-- ; 
		}

		if (count == 0) {
			majority = array[i] ; 
			count += 1 ; 
		}
		
	} 

	// Count the occurence of majority element , initialising count to zero 
	count = 0 ; 

	
	for (int i = 0 ; i < n ; ++i) { 
		if (array[i] == majority) count++ ; 

	}
	
	if (count > (int) floor(n / 2)) {  // if occurence is greater than n /2 
		printf("Answer is : %d\n" , majority) ; 
	}
	
	else { 
		printf("-1\n") ;
	}




	return 0 ; 
}