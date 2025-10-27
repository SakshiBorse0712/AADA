# include <stdio.h>
# include <stdlib.h>
# include <time.h>

int binarySearch(int a[1000],int n,int k)
{ 
    int start =0,end=n-1;
    int mid = (start+end)/2;

    if(a[mid] ==k)
    {
        return mid;
    }
    else if(a[mid] < k)
    {
        start = mid +1;
    }
    else if(a[mid] > k)
    {
        end = mid -1;
    }
    else
    {
         return -1;
    }
}

void bubbleSort(int a[1000],int n)
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
}

int main()
{
    int n,k;
    printf("Enter number of elements in array:");
    scanf("%d",&n);

    clock_t start_time = clock();

    int a[n];
    printf("Generated Array : ");
    for(int i=0;i<n;i++)
    {
        a[i] = rand() % 100 + 1;
        printf("%d ",a[i]);
    }

    printf("\n");

    bubbleSort(a,n);

    printf("Enter element to find:");
    scanf("%d",&k);

    if(binarySearch(a,n,k)!=-1)
    {
        printf("Element is found in index:%d\n" ,binarySearch(a,n,k)+1);
    }
    else if(binarySearch(a,n,k)==-1)
    {
        printf("NO FOUND");
    }

    clock_t end_time = clock();
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC ;
    printf("Time taken for linear search : %.6f sec\n",time_taken);

    return 0;
}