#include<stdio.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int divide (int data[], int left, int right) {
    int pivot = data[right];
    int i = (left - 1);
 
    for (int j = left; j <= right- 1; j++) {
        if (data[j] < pivot) {
            i++;
            swap(&data[i], &data[j]);
        }
    }
    swap(&data[i + 1], &data[right]);
    return i + 1;
} 

void quicksort(int data[], int left, int right) {
    if (left < right) {
        int index = divide(data, left, right);
        quicksort(data, left, index - 1);
        quicksort(data, index + 1, right);
    }
}


int main(int argc, char* argv){
    int test[10] = {
        10,
        9,
        8,
        7,
        3213123,
        5,
        4,
        3,
        2,
        1
    };
    int start = 0;
    int* end = &test[(sizeof(test) / sizeof(test[0])) - 1];
    quicksort(test, 0, (sizeof(test) / sizeof(test[0])) - 1);

    for(int i = 0; i < (sizeof(test) / sizeof(test[0])); ++i){
        printf("%i -> %i\n", i, test[i]);
    }

    return 0;
}
