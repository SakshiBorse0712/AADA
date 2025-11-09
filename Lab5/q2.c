#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randPartition(char a[], int low, int high) {
    int pivotIndex = low + rand() % (high - low + 1);
    char temp = a[pivotIndex];
    a[pivotIndex] = a[high];
    a[high] = temp;

    char pivot = a[high];
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

void quickSort(char a[], int low, int high) {
    if(low < high) {
        int pi = randPartition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

int main() {
    char a[15];
        printf("Enter Elements:");
    for(int i = 0; i < 15; i++) {
        scanf(" %c", &a[i]);
    }

    clock_t start = clock();
    quickSort(a, 0, 14);
    clock_t end = clock();

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

        printf("Sorted Array:");
    for(int i = 0; i < 15; i++) {
        printf("%c ", a[i]);
    }
    printf("\nTime taken: %lf seconds\n", time_taken);
    return 0;
}
