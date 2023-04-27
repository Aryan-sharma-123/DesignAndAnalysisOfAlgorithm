#include<stdio.h>
#include<stdlib.h>
int main()
{
	int arr[50][50],brr[50][50],crr[50][50],i,j;
	int n,m,c,r;
	printf("Enter the rows and columns of the first array: \n");
	scanf("%d%d",&n,&m);
	printf("\n Enter the elements into the array: \n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}


	printf("Your first array is: \n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}

	printf("\nEnter the rows and columns of the second array: \n");
	scanf("%d%d",&r,&c);
	printf("\n Enter the elements into the array: \n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",&brr[i][j]);
		}
	}

	printf("\nYour second array is: \n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%d ",brr[i][j]);
		}
		printf("\n");
	}
	
	if(n!=r)
	{
		printf("The matrix can't be multiplied: \n");
	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<c;j++)
		{
			crr[i][j]=0;
			for(int j=0;j<m;j++)
			{
				crr[i][j]+=arr[i][j]*brr[i][j];
			}
		}
	}

	printf("\nAfter multiplication of two matrix, the matrix is: \n");
	for(int i=0;i<n;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%d ",crr[i][j]);
		}
		printf("\n");
	}
  return 0;
}

