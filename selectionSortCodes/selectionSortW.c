#include <stdio.h>
#include <stdlib.h>

int main(){
	int size = 10000;
	int* array = (int *) malloc(sizeof(int) * size);
	
	if(array == NULL){
		printf("\nFalha ao alocar memoria.");
		exit(-1);
	}
	
	for(int i = 0; i < size; i++){
		array[i] = size-i-1;
	}
	
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
	
	free(array);
	return 0;	
}
