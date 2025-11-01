#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int a[],int n)
{
    int i,j,temp;
    for(i=1;i<n;i++)
    {
        temp = a[i];
        j=i-1;
        while(j>=0 && a[j]>temp)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1]=temp;
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
    insertionSort(a,n);
    clock_t end_time = clock();

    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC ;
    printf("\nTime taken for Insertion Sort : %.6f sec\n",time_taken);

    return 0;
}

