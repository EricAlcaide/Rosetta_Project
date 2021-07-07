/*
* C Program to Perform Quick Sort on a set of Entries taken from the user (Recursive Implementation)
*/
#include <stdio.h>
void quicksort (int [], int, int);
int main(){
	int array[50];
	int size, i;
	printf("Enter number of elements: \n");
	scanf("%d", &size); 
	printf("Enter the elements:\n");
	for (i = 0; i < size; i++){
		scanf("%d", &array[i]);
     } 
     quicksort(array, 0, size - 1);
     printf("Array after applying quick sort:\n");
	for (i = 0; i < size; i++){
		printf("%d ", array[i]);
	}
	printf("\n");
	return 0;
}
void quicksort(int array[], int low, int high){
	int pivot, i, j, temp;
	if (low < high){
		pivot = low;
		i = low;
		j = high;
		while (i < j) {
			while (array[i] <= array[pivot] && i <= high){
               	i++;
               }
			while (array[j] > array[pivot] && j >= low){
				j--;
			}
			if (i < j){
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
		temp = array[j];
		array[j] = array[pivot];
		array[pivot] = temp;
		quicksort(array, low, j - 1);
		quicksort(array, j + 1, high);
	}
}
