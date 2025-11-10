# include <stdio.h>
# define MAX 100

struct Item {
    int weight;
    int value;
    float ratio;
};

void bubbleSort(struct Item Items[],int n)
{
    for (int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(Items[j].ratio < Items[j+1].ratio)
            {
                struct Item temp = Items[j];
                Items[j] = Items[j+1];
                Items[j+1] =temp;
            }
        }
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

    bubbleSort(Items,n);

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