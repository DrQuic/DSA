#include <stdio.h>
void swap (int *value, int *value2) {
    int temp = *value;
    *value = *value2;
    *value2 = temp;
}

int partition(int arr[], int start, int finish) {
    int pivot = arr[finish];
    int i = start - 1;

    for(int j = start; j < finish; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(&arr[j], &arr[i]);
        };
    };
    swap(&arr[i + 1], &arr[finish]);
    return i + 1;
}
    
void quick_sort(int arr[], int start, int finish) {
    if (start < finish) {
        int pi = partition(arr, start, finish);
        quick_sort(arr, pi + 1, finish);
        quick_sort(arr, start, pi - 1);
    }
}

void printarray(int arr[], int size) {
    printf("[ ");
    for (int i = 0; i < size; i++) { 
        printf("%d, ", arr[i]);
    }
    printf("]\n");
};

int main() {
    int test_array[] = {1, 40, 80, 100, 4, 9};
    quick_sort(test_array, 0, 5);
    printarray(test_array, *(&test_array + 1) - test_array);
    return 0;
}
