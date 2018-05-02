#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void swap(int *num1, int *num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int partition(int *arr, int left, int right, int pivot) {
    int leftpointer = right -1, rightpointer = right;
    while (true) {
        while (arr[++leftpointer] <= pivot) {
            // do Nothing
        }
        while (rightpointer > 0 && arr[rightpointer--] >= pivot) {
            // do Nothing
        }
        if (leftpointer >= rightpointer) {
            break;
        }
        swap(&arr[leftpointer], &arr[rightpointer]);
    }
    swap(&arr[leftpointer], &arr[right]);
    return leftpointer;
}

void quick_sort(int *arr, int left, int right) {
    if (right - left <= 0) {
        return;
    }
    int pivot = arr[right];
    int partitionPoint = partition(arr, left, right, pivot);
    quick_sort(arr, left, partitionPoint -1);
    quick_sort(arr, partitionPoint + 1, right);
}

int main(void) {
    int arr[6] = {3,2,2,4,24,1};
    quick_sort(arr, 0, 5);
    for(int i = 0; i < 6; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}