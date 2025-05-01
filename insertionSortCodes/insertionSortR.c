#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int size = 10000;
	int* array = (int *) malloc(sizeof(int) * size);
	
	if(array == NULL){
		printf("\nFalha ao alocar memoria.");
		exit(-1);
	}
	
	for(int i = 0; i < size; i++){
		array[i] = rand() % 1001;
	}
	
	// insertion sort
	for (int i = 1; i < size; i++) {
    	int key = array[i];
    	int j = i - 1;
    	
	    while (j >= 0 && array[j] > key) {
	        array[j + 1] = array[j];
	        j--;
	    }
	    
    	array[j + 1] = key;
	}
	
	free(array);
	return 0;	
}
