#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(char a[],int n)
{
    int min,i,j,swap;
    for(i=0;i<n;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j] < a[min])
            {
                swap = a[j];
                a[j] = a[min];
                a[min] = swap;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter number of elements in array:");
    scanf("%d",&n);
    
    char a[n];

    srand(time(0));

    printf("Generated Array: ");
    for (int i = 0; i < n; i++) {
        a[i] = 'A' + (rand() % 26); 
        printf("%c ", a[i]);
    }
    printf("\n");

    clock_t start_time = clock();
    selectionSort(a, n);
    clock_t end_time = clock();

    printf("Sorted Array   : ");
    for (int i = 0; i < n; i++) {
        printf("%c ", a[i]);
    }
    printf("\n");

    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Time taken for Selection Sort on character array of size %d: %.6f sec\n", n, time_taken);

    return 0;
}
