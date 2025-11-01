#include <stdio.h>
#include <stdlib.h>

void insertionSort(char a[],int n)
{
    int i,j;
    char temp;
    for(i=1;i<n;i++)
    {
        temp = a[i];
        j=i-1;
        while(j>=0 && a[j]>temp)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1]=temp;
    }
}

int main() {
    int n;
    printf("Enter number of elements in array:");
    scanf("%d",&n);
    
    char a[n];

    printf("Generated Array: ");
    for (int i = 0; i < n; i++) {
        a[i] = 'A' + (rand() % 26);
        printf("%c ", a[i]);
    }
    printf("\n");

    insertionSort(a, n);

    printf("Sorted Array   : ");
    for (int i = 0; i < n; i++) {
        printf("%c ", a[i]);
    }
    printf("\n");
    return 0;
}