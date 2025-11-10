# include <stdio.h>
# define MAX 100

struct Item {
    int weight;
    int value;
    float ratio;
};

void swap(struct Item a[],int i,int j)
{
    struct Item temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int partition(struct Item a[],int n,int low,int high)
{
    float pivot = a[high].ratio;
    int i = low - 1;

    for(int j=low;j<high;j++)
    {
        if(a[j].ratio >= pivot)
        {
            i++;
            swap(a,i,j);
        }
    }
    swap(a,i+1,high);
    return i+1 ;
}

void quickSort(struct Item a[],int n,int low,int high)
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

    quickSort(Items,n,0,n-1);

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