#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int a[100],int n)
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
    printf("Sorted array:");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}

int main()
{
    int a[100],n,i;
    srand(time(0));
    clock_t start_time = clock();
    printf("Enter number of elements in array:");
    scanf("%d",&n);

    printf("Enter elements in array:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    bubbleSort(a,n);
    
    clock_t end_time = clock();
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC ;
    printf("\nTime taken for linear search : %.6f sec\n",time_taken);

    return 0;
}