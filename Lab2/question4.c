#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(char arr[], int n) {
    int i, j;
    char temp;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter number of elements in array:");
    scanf("%d",&n);
    
    char arr[n];

    srand(time(0));

    printf("Generated Array: ");
    for (int i = 0; i < n; i++) {
        arr[i] = 'A' + (rand() % 26); 
        printf("%c ", arr[i]);
    }
    printf("\n");

    clock_t start_time = clock();
    bubbleSort(arr, n);
    clock_t end_time = clock();

    printf("Sorted Array   : ");
    for (int i = 0; i < n; i++) {
        printf("%c ", arr[i]);
    }
    printf("\n");

    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Time taken for Bubble Sort on character array of size %d: %.6f sec\n", n, time_taken);

    return 0;
}
