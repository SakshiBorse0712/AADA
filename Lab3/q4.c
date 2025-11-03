#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int a[100],int n,int i,int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int partition(int a[100],int n,int low,int high)
{
    int pivot = a[high];
    int i = low - 1;

    for(int j=low;j<high;j++)
    {
        if(a[j] < pivot)
        {
            i++;
            swap(a,n,i,j);
        }
    }
    swap(a,n,i+1,high);
    return i+1 ;
}

void quickSort(int a[100],int n,int low,int high)
{
    if(low < high)
    {
        int pi=partition(a,n,low,high);
        quickSort(a,n,low,pi-1);
        quickSort(a,n,pi+1,high);
        
    }
}

int main()
{
    int a[100],n;
    printf("Enter number of elements in array:");
    scanf("%d",&n);

    printf("Enter elements in array:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    clock_t start_time = clock();

    quickSort(a,n,0,n-1);

    clock_t end_time = clock();

    printf("Sorted Array:");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }

    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC ;
    printf("\nTime taken for Merge Sort : %.6f sec\n",time_taken);
    
    return 0;
}