#include<stdio.h>
#include<stdlib.h>
void selectionsort(int arr[],int n)
{
	int i,j,min,temp;
	int count=0;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
		count++;
			if(arr[j]<arr[min])
			{
				min=j;
			}
		}
		temp=arr[i];
		arr[i]=arr[min];
		arr[min]=temp;

	}
	printf("The count is: %d\n",count);
}

int main()
{
	int arr[100],n;
	printf("Enter the size of the list: \n");
	scanf("%d",&n);
	printf("\nEnter the elements into the array: \n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}

	printf("\nBefore the sorting the list, the list is: \n");
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}

	selectionsort(arr,n);
	printf("\nAfter sorting the list using selectionsort is: \n");
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}
