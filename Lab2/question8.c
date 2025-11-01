#include <stdio.h>
#include <string.h>

void selectionSort(char arr[][50], int n) {
    int i, j, minIndex;
    char temp[50];

    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (strcmp(arr[j], arr[minIndex]) < 0) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            strcpy(temp, arr[i]);
            strcpy(arr[i], arr[minIndex]);
            strcpy(arr[minIndex], temp);
        }
    }
}

int main() {
    int n = 5;
    char arr[5][50];

    printf("Enter %d strings:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%s", arr[i]);
    }

    selectionSort(arr, n);

    printf("\nSorted Strings in Ascending Order:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
    }

    return 0;
}
