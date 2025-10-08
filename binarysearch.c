#include <stdio.h>
int binarysearch(int arr[],int n,int key)
{
    int first = 0;
    int last = n-1;
    int mid;
    while(first<=last)
    {
    mid = (first+last)/2;
        if(arr[mid]==key)
        {
            return mid;
        }
        else if(arr[mid]>key)
        {
            last = mid - 1;
        }
        else
            first = mid + 1;
    }
    return -1;
}
int main()
{
    int n,key;
    printf("Enter the length of the array:\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array in ascending order:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the search number:\n");
    scanf("%d",&key);
    int result = binarysearch(arr,n,key);
    if (result!=-1)
        printf("Element found at the position:%d",result+1);
    else 
        printf("Element not found");
}