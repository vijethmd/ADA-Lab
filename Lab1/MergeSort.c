#include<stdio.h>
#include<time.h>
#define MAX 20

void merge(int A[],int n,int B[],int m,int arr[])
{
    int k = 0;
    int i = 0, j = 0;
    while(i < n && j < m)
    {
        if(A[i] < B[j])
        {
            arr[k] = A[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = B[j];
            k++;
            j++;
        }
    }
    while(i < n)
    {
        arr[k] = A[i];
        k++;
        i++;
    }
    while(j < m)
    {
        arr[k] = B[j];
        k++;
        j++;
    }
}

void mergeSort(int arr[MAX],int n)
{
    if(n <= 1) return;
    int mid = n/2;
    int left[mid];
    int right[n - mid];
    for(int i = 0; i < mid;i++)
    {
        left[i] = arr[i];
    }
    for(int j = mid;j < n;j++)
    {
        right[j - mid] = arr[j];
    }
    mergeSort(left,mid);
    mergeSort(right,n - mid);
    merge(left,mid,right,n - mid,arr);
}

int main()
{
    int n;
    printf("\nEnter the number of elements : ");
    scanf("%d",&n);
    int arr[MAX];
    printf("\nEnter array elements : \n");
    for(int i = 0;i < n;i++)
    {
        scanf("%d",&arr[i]);
    }
    mergeSort(arr,n);
    printf("\n");
    for(int i = 0;i < n;i++)
    {
        printf("%d ",arr[i]);
    }
}
