#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);
}

void heapSort(int arr[], int n) {
    buildMaxHeap(arr, n);
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        maxHeapify(arr, i, 0);
    }
}

void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 100000;
}

int main() {
    int sizes[] = {25, 35, 1000, 10000, 100000, 1000000};
    int numTests = sizeof(sizes) / sizeof(sizes[0]);

    printf("InputSize,TimeSeconds\n");

    for (int t = 0; t < numTests; t++) {
        int n = sizes[t];
        int *arr = (int *)malloc(n * sizeof(int));
        generateRandomArray(arr, n);

        clock_t start = clock();
        heapSort(arr, n);
        clock_t end = clock();

        double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
        printf("%d,%.6f\n", n, time_taken);

        free(arr);
    }

    return 0;
}
