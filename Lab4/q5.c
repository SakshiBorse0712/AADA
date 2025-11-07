#include <stdio.h>
#include <string.h>

#define MAX 50

void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

void minHeapify(char heap[], int n, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && heap[left] < heap[smallest])
        smallest = left;

    if (right < n && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        minHeapify(heap, n, smallest);
    }
}

void buildMinHeap(char heap[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        minHeapify(heap, n, i);
    }
}

void insertMinHeap(char heap[], int *n, char value) {
    int i = (*n)++;
    heap[i] = value;

    while (i != 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void heapSort(char arr[], int n) {
    buildMinHeap(arr, n);
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        minHeapify(arr, i, 0);
    }
}

void printArray(char arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%c ", arr[i]);
    printf("\n");
}

void findMax(char arr[], int n) {
    char max = arr[0];
    int index = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
            index = i;
        }
    }
    printf("Max Element: %c at index %d\n", max, index);
}

void findMin(char arr[], int n) {
    char min = arr[0];
    int index = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
            index = i;
        }
    }
    printf("Min Element: %c at index %d\n", min, index);
}

int main() {
    char heap[MAX];
    int n = 15;

    printf("Enter 15 characters:\n");
    for (int i = 0; i < 15; i++) {
        printf("Character %d: ", i + 1);
        scanf(" %c", &heap[i]);
    }

    buildMinHeap(heap, n);
    printf("\nMin Heap built:\n");
    printArray(heap, n);

    char val1, val2;
    printf("\nEnter first value to insert: ");
    scanf(" %c", &val1);
    insertMinHeap(heap, &n, val1);

    printf("Enter second value to insert: ");
    scanf(" %c", &val2);
    insertMinHeap(heap, &n, val2);

    printf("\nHeap after insertion:\n");
    printArray(heap, n);

    heapSort(heap, n);
    printf("\nHeap after Heap Sort:\n");
    printArray(heap, n);

    if (n > 4) {
        heap[4] -= 7;
        printf("\nAfter decrementing index 4 by 7:\n");
        printArray(heap, n);
    }

    if (n > 0) {
        heap[n - 1] -= 16;
        printf("\nAfter decrementing last index by 16:\n");
        printArray(heap, n);
    }

    printf("\nFinding Max and Min:\n");
    findMax(heap, n);
    findMin(heap, n);

    return 0;
}
