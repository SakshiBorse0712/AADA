# include <stdio.h>
# define MAX 100

struct Item {
    int weight;
    int value;
    float ratio;
};

void merge(struct Item a[],int n,int left ,int mid ,int right)
{
    int n1,n2;
    n1 = mid - left + 1;
    n2 = right - mid;
    struct Item leftArray[n1],rightArray[n2];

    for(int i=0;i<n1;i++)
    {
        leftArray[i] = a[left + i];
    }

    for(int j=0;j<n2;j++)
    {
        rightArray[j] = a[mid + 1 + j];
    }

    int i=0,j=0,k=left;
    while(i < n1  &&  j < n2)
    {
        if(leftArray[i].ratio >= rightArray[j].ratio)
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

void mergeSort(struct Item a[],int n,int left,int right)
{
    if(left < right)
    {
        int mid = left + (right-left) /2 ;
        mergeSort(a,n,left,mid);
        mergeSort(a,n,mid+1,right);
        merge(a,n,left,mid,right);
    }
}

int main()
{
    struct Item Items[MAX];
    int n,i,j;
    printf("Enter Number of Items:");
    scanf("%d",&n);

    float capacity;
    float totalValue = 0.0;
    float fraction;

    printf("Enter Weight and Value of %d items \n",n);
    for(int i=0;i<n;i++)
    {
        printf("Item %d Weight : ",i+1);
        scanf("%d",&Items[i].weight);
        printf("Item %d Value : ",i+1);
        scanf("%d",&Items[i].value);
        Items[i].ratio = (float)Items[i].value / (float)Items[i].weight;
    }

    printf("Enter the capacity : ");
    scanf("%f",&capacity);

    mergeSort(Items,n,0,n-1);

    printf("\nItems sorted by value/weight ratio (descending):\n");
    printf("Item\tValue\tWeight\tRatio\n");
    for (i = 0; i < n; i++)
    printf("%d\t%d\t%d\t%.2f\n", i + 1, Items[i].value, Items[i].weight, Items[i].ratio);

    printf("\n Selecting items \n");
    for (i = 0; i < n; i++) {
        if (capacity == 0) break;
        if (Items[i].weight <= capacity) {
            totalValue += Items[i].value;
            capacity -= Items[i].weight;
            printf("Took full Item %d (Value = %d)\n", i + 1, Items[i].value);
        } else {
            fraction = capacity / Items[i].weight;
            totalValue += Items[i].value * fraction;
            printf("Took %.2f fraction of Item %d (Value = %.2f)\n", fraction, i + 1, Items[i].value * fraction);
            capacity = 0;
        }
    }

    printf("\nMaximum total value (profit) = %.2f\n", totalValue);
    return 0;
}