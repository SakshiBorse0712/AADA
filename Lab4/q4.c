#include <stdio.h>

#define MAX_SIZE 100

int heap[MAX_SIZE];
int heapSize = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int index) {
    while (index != 0 && heap[(index - 1) / 2] > heap[index]) {
        swap(&heap[(index - 1) / 2], &heap[index]);
        index = (index - 1) / 2;
    }
}

void heapifyDown(int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heapSize && heap[left] < heap[smallest])
        smallest = left;

    if (right < heapSize && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != index) {
        swap(&heap[index], &heap[smallest]);
        heapifyDown(smallest);
    }
}

void insert(int value) {
    if (heapSize >= MAX_SIZE) {
        printf("Heap is full!\n");
        return;
    }
    heap[heapSize] = value;
    heapifyUp(heapSize);
    heapSize++;
}

void buildHeap() {
    for (int i = (heapSize / 2) - 1; i >= 0; i--) {
        heapifyDown(i);
    }
}

int extractMin() {
    if (heapSize <= 0)
        return -1;

    int root = heap[0];
    heap[0] = heap[heapSize - 1];
    heapSize--;
    heapifyDown(0);

    return root;
}

void heapSort(int sorted[]) {
    int originalSize = heapSize;
    for (int i = 0; i < originalSize; i++) {
        sorted[i] = extractMin();
    }
    heapSize = originalSize; 
}

int main() {
    int i, value;
    int sorted[ MAX_SIZE ];

    printf("Enter 15 integers:\n");
    for (i = 0; i < 15; i++) {
        scanf("%d", &value);
        insert(value);
    }

    printf("Enter two more integers to insert into the Min Heap:\n");
    for (i = 0; i < 2; i++) {
        scanf("%d", &value);
        insert(value);
    }

    printf("\nHeap before sorting:\n");
    for (i = 0; i < heapSize; i++) {
        printf("%d ", heap[i]);
    }

    heapSort(sorted);

    printf("\n\nSorted elements using Heap Sort:\n");
    for (i = 0; i < 17; i++) {
        printf("%d ", sorted[i]);
    }

    printf("\n\nSorted elements after decrementing by 3:\n");
    for (i = 0; i < 17; i++) {
        sorted[i] -= 3;
        printf("%d ", sorted[i]);
    }

    printf("\n");

    return 0;
}
