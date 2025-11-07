#include <stdio.h>
#include <limits.h>

#define SIZE 25

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

int deleteRoot(int arr[], int *n) {
    if (*n <= 0) return -1;

    int root = arr[0];
    arr[0] = arr[*n - 1];
    (*n)--;

    heapify(arr, *n, 0);
    return root;
}

void findMax(int arr[], int n, int *maxVal, int *index) {
    *maxVal = arr[0];
    *index = 0;
}

void findMin(int arr[], int n, int *minVal, int *index) {
    *minVal = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (arr[i] < *minVal) {
            *minVal = arr[i];
            *index = i;
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int heap[SIZE] = {35, 12, 43, 8, 51, 60, 18, 22, 17, 29, 31, 6, 5, 40, 15, 7, 3, 26, 10, 11, 14, 24, 21, 19, 9};
    int n = SIZE;

    printf("Original Array:\n");
    printArray(heap, n);

    buildMaxHeap(heap, n);
    printf("\nAfter building Max Heap:\n");
    printArray(heap, n);

    heap[8] += 29;
    buildMaxHeap(heap, n);  
    printf("\nAfter incrementing index 8 by 29:\n");
    printArray(heap, n);

    heap[10] += 45;
    buildMaxHeap(heap, n);
    printf("\nAfter incrementing index 10 by 45:\n");
    printArray(heap, n);

    int deletedValue = deleteRoot(heap, &n);
    printf("\nAfter deleting root (%d):\n", deletedValue);
    printArray(heap, n);

    int maxVal, maxIndex;
    findMax(heap, n, &maxVal, &maxIndex);
    printf("\nMax Value: %d at Index: %d\n", maxVal, maxIndex);

    int minVal, minIndex;
    findMin(heap, n, &minVal, &minIndex);
    printf("Min Value: %d at Index: %d\n", minVal, minIndex);

    return 0;
}
