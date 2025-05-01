#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int size = 200000;
	int* array = (int *) malloc(sizeof(int) * size);
	srand(time(NULL));
	
	if(array == NULL){
		printf("\nFalha ao alocar memoria.");
		exit(-1);
	}
	
	for(int i = 0; i < size; i++){
		array[i] = rand() % 1001;
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
