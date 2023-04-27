#include<stdio.h>
#include<stdlib.h>
int main()
{
    int arr[100],n,i,j,temp;
    printf("Enter the size of the list: \n");
    scanf("%d",&n);
    printf("Enter the elements into the list: \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    for(i=1;i<n;i++)
    {
        temp=arr[i];
        for(j=i-1;arr[j]>temp;j-- && j>=0)
        {
            arr[j+1]=arr[j];
        }
        arr[j+1]=temp;
    }

    printf("The sorted array using insertion sort is : \n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
    return 0;
}
