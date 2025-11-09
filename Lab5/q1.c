#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randPartition(int a[], int low, int high) {
    int pivotIndex = low + rand() % (high - low + 1);
    int temp = a[pivotIndex];
    a[pivotIndex] = a[high];
    a[high] = temp;

    int pivot = a[high];
    int i = low - 1;
    for(int j = low; j < high; j++) {
        if(a[j] <= pivot) {
            i++;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    temp = a[i+1];
    a[i+1] = a[high];
    a[high] = temp;
    return i+1;
}

void quickSort(int a[], int low, int high) {
    if(low < high) {
        int pi = randPartition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

int main() {
    int a[15];
    printf("Enter Elements:");
    for(int i = 0; i < 15; i++) {
        scanf("%d", &a[i]);
    }

    clock_t start = clock();
    quickSort(a, 0, 14);
    clock_t end = clock();

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Sorted Array:");
    for(int i = 0; i < 15; i++) {
        printf("%d ", a[i]);
    }
    printf("\nTime taken: %lf seconds\n", time_taken);
    return 0;
}
