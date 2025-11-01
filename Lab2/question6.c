#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int a[100],int n)
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
    
    printf("\n\nSorted array:");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}

int main()
{
    int n,i;
    srand(time(0));

    printf("Enter number of elements in array:");
    scanf("%d",&n);
    int a[n];

    printf("Generated Array : ");
    for(int i=0;i<n;i++)
    {
        a[i] = rand() % 1000 + 1;
        printf("%d ",a[i]);
    }
    
    clock_t start_time = clock();
    selectionSort(a,n);
    clock_t end_time = clock();

    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC ;
    printf("\nTime taken for Bubble Sort : %.6f sec\n",time_taken);

    return 0;
}