#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int a[],int n)
{
    int i,j,temp;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(a[j] > a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    
    printf("\nSorted array:");
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
    bubbleSort(a,n);
    clock_t end_time = clock();

    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC ;
    printf("\nTime taken for Bubble Sort : %.6f sec\n",time_taken);

    return 0;
}