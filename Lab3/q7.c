//  MERGE SORT

# include <stdio.h>
# include <stdlib.h>
# include <time.h>

void merge(int a[],int left,int mid ,int right)
{
    int n1,n2;
    n1 = mid -left+1;
    n2 = right - mid;
    int leftArray[n1],rightArray[n2];

    for (int i = 0; i < n1; i++)
        leftArray[i] = a[left + i];
    for (int j = 0; j < n2; j++)
        rightArray[j] = a[mid + 1 + j];

    int i=0,j=0,k=left;

    while(i < n1 && j < n2)
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

void mergeSort(int a[],int left,int right)
{
    if (left < right) {
    int mid = left + (right - left) / 2;
    mergeSort(a, left, mid);
    mergeSort(a, mid + 1, right);
    merge(a, left, mid, right);
}

}

// QUICK SORT

int swap(int a[],int i,int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int partition(int a[],int low , int high)
{
    int pivot = a[high];
    int i = low - 1;
    
    for(int j = low ; j < high ; j++)
    {
        if(a[j] < pivot)
        {
            i++;
            swap(a,i,j);
        }
    }
    swap(a,i+1,high);
    return i+1;
}

void quickSort(int a[], int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi+1, high);
    }
}

int main()
{
    int n;
    printf("Enter number of elements in array:");
    scanf("%d",&n);

    int *a1 = (int *)malloc(n * sizeof(int));
    int *a2 = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        a1[i] = i + 1;
        a2[i] = i + 1;
    }

    clock_t start_time = clock();
    mergeSort(a1,0,n-1);
    clock_t end_time = clock();

    double time_merge = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    start_time = clock();
    quickSort(a2,0,n-1);
    end_time = clock();

    double time_quick = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Merge Sort Time : %f seconds\n", time_merge);
    printf("Quick Sort Time : %f seconds\n", time_quick);


    return 0;
}