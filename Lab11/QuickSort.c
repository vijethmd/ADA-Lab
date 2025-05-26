#include<stdio.h>
#include<time.h>
#define MAX 100

void swap(int arr[],int a,int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int partition(int arr[],int low,int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    while(i <= j)
    {
        while(i <= high && arr[i] <= pivot) i++;
        while(arr[j] > pivot) j--;
        if(i < j) swap(arr,i,j);
        if(i >= j) break;
    }
    swap(arr,low,j);
    return j;
}

void quickSort(int arr[],int low,int high)
{
    if(low < high)
    {
        int p = partition(arr,low,high);
        quickSort(arr,low,p-1);
        quickSort(arr,p+1,high);
    }
}

int main()
{
    int n;
    printf("\nEnter number of elements : ");
    scanf("%d",&n);
    int arr[MAX];
    printf("\nEnter array elements : \n");
    for(int i = 0;i < n;i++)
    {
        scanf("%d",&arr[i]);
    }
    clock_t start = clock();
    quickSort(arr,0,n-1);
    clock_t end = clock();
    float remaining = (float)(end - start)/CLOCKS_PER_SEC;
    printf("\n");
    for(int i = 0;i < n;i++)
    {
        printf("%d ",arr[i]);
    }
}
