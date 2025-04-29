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
	
	for(int i = 0; i < size - 1; i++){
		int minorValue = i;
		
		for(int j = i + 1; j < size; j++){
			if(array[minorValue] > array[j]){
				minorValue = j;
			}
		}
		
		if(minorValue != i){
			int varAux = array[i];
			array[i] = array[minorValue];
			array[minorValue] = varAux;
		}
	}
	
	printArray(array, size);
	free(array);
	return 0;	
}
