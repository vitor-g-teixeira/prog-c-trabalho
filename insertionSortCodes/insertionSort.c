#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int* array, int size){
	for(int i = 0; i < size; i++){
		if(i == 0) printf("[ ");
		printf("%d ", array[i]);
		if(i == size - 1) printf("]");
	}
}

int main(){
	int size = 10;
	int* array = (int *) malloc(sizeof(int) * size);
	srand(time(NULL));
	
	if(array == NULL){
		printf("\nFalha ao alocar memoria.");
		exit(-1);
	}
	
	for(int i = 0; i < size; i++){
		array[i] = rand() % 1001;
	}
	
	printArray(array, size);
	printf("\n\n");
	
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
	
	printArray(array, size);
	free(array);
	return 0;	
}
