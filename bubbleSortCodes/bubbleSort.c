#include <stdio.h>
#include <stdlib.h>

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
	
	if(array == NULL){
		printf("\nFalha ao alocar memoria.");
		exit(-1);
	}
	
	for(int i = 0; i < size; i++){
		array[i] = size-i-1;
	}
	
	printArray(array, size);
	printf("\n\n");
	
	int keepGoing = 1;
	
	while(keepGoing){
		keepGoing = 0;
		for(int i = 0; i < size - 1; i++){
			if(array[i] > array[i + 1]){
				int auxVar = array[i];
				array[i] = array[i + 1];
				array[i + 1] = auxVar;
				keepGoing = 1;
			}
		}
	}
	
	printArray(array, size);
	
	free(array);
	return 0;
}
