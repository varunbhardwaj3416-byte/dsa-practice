#include <stdio.h>

int array[100000] ; 
int main(){
	int n ; 
	printf("Enter the no of element's : \n") ; 
	scanf("%d" , &n) ; 

	int temp ; 
	printf("Enter the elements : \n") ; 

	// For secondMax and Max we use two counters 
	int sM , M ; 
	sM = M = -1 ; 

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
	printf("%d \n" , sM) ; 
	} 


	return 0 ; 
}