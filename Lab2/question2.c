# include <stdio.h>

int binarySearch(char a[15],int low,int high,char k)
{
    if(low <= high)
    {
        int mid = (low+high)/2;

        if(a[mid] == k)
        {
            return mid;
        }
        else if (a[mid] > k)
        {
            return binarySearch(a,low,mid-1,k);
        }
        else if(a[mid] < k)
        {
            return binarySearch(a,mid +1,high,k);
        }
        else {
            return -1;
        }
    }
}

int main()
{
    int n;
    char k,a[15];
    printf("Enter number of elements in array :");
    scanf("%d",&n);

    printf("Enter character elements :");
    for(int i=0;i<n;i++)
    {
        scanf(" %c",&a[i]);
    }

    printf("Enter character element to find:");
    scanf(" %c",&k);

    int result = binarySearch(a,0,n-1,k);

    if(result!=-1)
    {
            printf("Element is found in index %d\n",result);
    }
    else 
    {
        printf("Not Found\n");
    }

    printf("Memory Address of key value : %p\n",(int *)&a[result]);
}