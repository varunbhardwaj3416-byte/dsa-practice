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
	
	int majority = array[0], count = 0 ; 
	 
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
	
	if (count > (int) floor(n / 2)) { 
		printf("Answer is : %d\n" , majority) ; 
	}
	
	else { 
		printf("-1\n") ;
	}




	return 0 ; 
}