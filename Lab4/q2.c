#include <stdio.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void heapify(int arr[], int n, int i) 
{
    int largest = i;          
    int left = 2 * i + 1;     
    int right = 2 * i + 2;    

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n) 
{
    int startIdx = (n / 2) - 1;

    for (int i = startIdx; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

void insertElement(int arr[], int *n, int value) {
    int i = *n;  
    arr[i] = value;
    (*n)++;  

    while (i != 0 && arr[(i - 1) / 2] < arr[i]) 
    {
        swap(&arr[i], &arr[(i - 1) / 2]);
        i = (i - 1) / 2;  
    }
}

void printHeap(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int a[15];
    int n,value;
    printf("Enter number of elements:");
    scanf("%d",&n);

    printf("Enter integers:\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &a[i]);
    }
    printf("\nEnter elements to insert:");
    scanf("%d",&value);

    buildMaxHeap(a, n);
    insertElement(a,&n,value);
    printHeap(a,n);

    printf("\n");
    return 0;
}
