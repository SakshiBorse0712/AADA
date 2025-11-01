#include <stdio.h>
#include <string.h>

void bubbleSort(char arr[][50], int n) 
{
    char temp[50];
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (strcmp(arr[j], arr[j + 1]) > 0) 
            {
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], temp);
            }
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

    bubbleSort(arr, n);

    printf("\nSorted Strings in Ascending Order:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
    }

    return 0;
}
