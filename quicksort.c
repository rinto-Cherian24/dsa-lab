#include <stdio.h>
void swap(int *a,int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(int arr[],int low,int high){
    int pivot = arr[high];
    int i = low-1;
    for(int j=low;j<high;++j){
        if(arr[j]<=pivot){
            ++i;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return i+1;
}
void quicksort(int arr[],int low,int high){
    if(low<high){
        int p = partition(arr,low,high);
        quicksort(arr,low,p-1);
        quicksort(arr,p+1,high);
    }
}
int main() {
    int n;
    printf("Enter the number of elements in the array:\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for(int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }
    printf("Before sorting:\n");
    for(int i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }
    printf("\nAfter sorting:\n");
    quicksort(arr,0,n-1);
    for(int i =0 ;i < n; i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
