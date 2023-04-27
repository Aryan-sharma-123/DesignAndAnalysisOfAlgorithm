#include<stdio.h>
#include<stdlib.h>
void largest(int arr[],int n)
{
	int max=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]>max)
		{
			max=arr[i];
		}
	}
	printf("The largest element in the list is: \n%d",max);
}

int main()
{
	int n,arr[100],i;
	printf("Enter the size of the list: \n");
	scanf("%d",&n);
	printf("\nEnter the elements into the list: \n");

	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}

	largest(arr,n);
	return 0;
}