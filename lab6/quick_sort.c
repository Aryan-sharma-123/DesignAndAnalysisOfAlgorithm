#include<stdio.h>
#include<stdlib.h>
void swap(int *arr,int *brr)
{
    int temp;
    temp=*arr;
    *arr=*brr;
    *brr=temp;
}
int partition(int *arr,int lb,int ub)
{
    int pivot=arr[lb];
    int i=lb+1;
    int j=ub;

    while(i<j)
    {
        while(arr[i]<=pivot)
        { 
            i++;
        }

        while(arr[j]>pivot)
        {
            j--;
        }

        if(i<j)
        {
            swap(&arr[i],&arr[j]);
        }  
    }
    swap(&arr[lb],&arr[j]);
    return j;
}

void quicksort(int *arr,int lb,int ub)
{
    if(lb<ub)
    {
        int pivot=partition(arr,lb,ub);
        quicksort(arr,lb,pivot-1);
        quicksort(arr,pivot+1,ub);
    }
}
int main()
{
    int n,arr[100];
    printf("Enter the size of the array: \n");
    scanf("%d",&n);

    printf("\nEnter the elements into the array: \n");\
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    quicksort(arr,0,n-1);
    printf("\nAfter sorting the array is: \n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}