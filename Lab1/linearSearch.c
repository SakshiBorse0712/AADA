#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int linearSearch(int a[1000],int n,int k)
{
    for(int i=0;i<n;i++)
    {
        if(a[i] == k)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int n,k;
    srand(time(0));

    clock_t start_time = clock();

    printf("Enter number of elements in array:");
    scanf("%d",&n);

    int a[n];
    printf("Generated Array : ");
    for(int i=0;i<n;i++)
    {
        a[i] = rand() % 100 + 1;
        printf("%d ",a[i]);
    }

    printf("\n");

    printf("Enter element to find:");
    scanf("%d",&k);


    if(linearSearch(a,n,k)!=-1)
    {
        printf("Element is found in index %d\n",linearSearch(a,n,k));
    }
    else {
        printf("NOT FOUND");
    }

    clock_t end_time = clock();
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC ;
    printf("Time taken for linear search : %.6f sec\n",time_taken);

    return 0;
}