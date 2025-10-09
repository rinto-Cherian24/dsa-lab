#include <stdio.h>
void insertionSort(int arr[],int n)
{
    int j,key;
    for(int i=1;i<n;i++)
    {
        key = arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1] = arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}
void printArray(int arr[],int n)
{
    printf("Sorted Array:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}
int main()
{
    int n;
    printf("Enter the length of the array:\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for(int i =0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    insertionSort(arr,n);
    printArray(arr,n);
}