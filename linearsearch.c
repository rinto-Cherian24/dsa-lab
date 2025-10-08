#include <stdio.h>
int linearsearch(int arr[],int n,int key)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==key)
            return i;
    }
    return -1;
}
int main()
{
    int n,key;
    printf("Enter the length of the array:\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the search number:\n");
    scanf("%d",&key);
    int result = linearsearch(arr,n,key);
    if (result!=-1)
    {
        printf("Element found at position:%d",result+1);
    }
    else 
        printf("Element not found");
}