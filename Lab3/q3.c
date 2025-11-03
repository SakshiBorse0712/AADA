#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int n,int a[n],int left,int mid,int right)
{
    int n1,n2;
    n1 = mid - left +1;
    n2 = right - mid;
    int leftArray[n1],rightArray[n2];

    for(int i=0;i<n1;i++)
    {
        leftArray[i] = a[left +i];
    }

    for(int j=0;j<n2;j++)
    {
        rightArray[j] = a[mid + 1 + j];
    }

    int i=0,j=0,k=left;
    while(i < n1  &&  j < n2)
    {
        if(leftArray[i] <= rightArray[j])
        {
            a[k] = leftArray[i];
            i++;
        }
        else
        {
            a[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while(i < n1)
    {
        a[k] = leftArray[i];
        i++;
        k++;
    }

    while(j < n2)
    {
        a[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergeSort(int n,int a[n],int left,int right)
{
    if(left < right)
    {
        int mid = left + (right-left) /2 ;
        mergeSort(n,a,left,mid);
        mergeSort(n,a,mid+1,right);
        merge(n,a,left,mid,right);
    }
}

int main()
{
    int n;
    printf("Enter Number of elements in array:");
    scanf("%d",&n);

    int a[n];
    printf("Generated Array : ");
    for(int i=0;i<n;i++)
    {
        a[i] = rand() % 100 + 1;
        printf("%d ",a[i]);
    }

    clock_t start_time = clock();

    mergeSort(n,a,0,n-1);

    clock_t end_time = clock();

    printf("\nSorted Array:");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
 
    
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC ;
    printf("\nTime taken for Merge Sort : %.6f sec\n",time_taken);

}