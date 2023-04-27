#include<stdio.h>
#include<stdlib.h>
void merge(int arr[],int lb,int mid,int ub)
{
    int i=lb;
    int j=mid+1;
    int k=lb;
    int brr[100];
    int count=0;

    while(i<=mid && j<=ub)
    {
        if(arr[i]<arr[j])
        {
            brr[k]=arr[i];
            k++;
            i++;
        }
        else
        {
            brr[k]=arr[j];
            j++;
            k++;
        }
    }

    if(i>mid)
    {
        while(j<=ub)
        {
            brr[k]=arr[j];
            j++;
            k++;
        }
    }
    else
    {
        while(i<=mid)
        {
            brr[k]=arr[i];
            i++;
            k++;
        }
    }

    for(int p=lb;p<=ub;p++)
    {
        arr[p]=brr[p];
    }
    printf("%d",count);
}

void mergesort(int arr[],int lb,int ub)
{
    if(lb<ub)
    {
        int mid=(lb+ub)/2;
        mergesort(arr,lb,mid);
        mergesort(arr,mid+1,ub);
        merge(arr,lb,mid,ub);
    }
}

int main()
{
    int n,arr[100];
    printf("Enter the size of the array: \n");
    scanf("%d",&n);
    printf("\n Enter the elements into the array: \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    mergesort(arr,0,n-1);
    printf("\n After sorting the array is: \n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}
