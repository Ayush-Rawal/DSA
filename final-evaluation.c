#include<stdio.h>
#include<stdlib.h>

/* 
* Implement Insertion sort using binary search
*/

/* Using Array or Pointer?
* Ans = Array, because binary search is easier to implement in array
*/

void Print_Array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d\n", arr[i]);
    }
}

// Use binary search to find index where number should be inserted
int Binary_Search(int *arr, int lastIndex, int num) {
    int i = 0, j = lastIndex, mid = lastIndex / 2;
    while (i <= mid && mid <= j) {
        if (num == arr[mid] || i == j) {
            return mid;
        } else if (num < arr[mid]) {
            j = mid;
        } else if (num > arr[mid]) {
            i = mid + 1;
        }
        mid = (i + j) / 2;
    }
    return mid;
}

void Insertion_Sort(int *arr, int n) {
    int i, j;
    for (i = 1; i < n; i++) {
        // array upto i is sorted, insert a[i] in correct position
        int pos = Binary_Search(arr, i, arr[i]);
        // Insert into position
        int temp = arr[i];
        for (int j = i; j > pos; j--) {
            arr[j] = arr[j - 1];
        }
        arr[pos] = temp;
    }
}

int main(void) {
    int n, *arr;
    printf("Enter number of elements\n");
    scanf("%d", &n);
    arr = (int *)calloc(n, sizeof(int));
    printf("\nEnter elements\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    Insertion_Sort(arr, n);
    printf("\nSorted array:\n");
    Print_Array(arr, n);
    return 0;
}