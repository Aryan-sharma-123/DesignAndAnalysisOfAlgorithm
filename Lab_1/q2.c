//graph representations

#include<stdio.h>
#include<stdlib.h>

typedef struct node* nodeptr;

struct node
{
	int vertex;
	nodeptr link;
};

nodeptr addNode(int x){
	nodeptr temp=(nodeptr)malloc(sizeof(struct node));
	temp->vertex=x;
	temp->link=NULL;
	return temp;
}

void displayList(nodeptr head){
	nodeptr temp=head;
	while(temp){
		printf("%d\t",temp->vertex);
		temp=temp->link;
	}
	printf("\n");
}

void main()
{
	int m,n,i,j;
	char ch='n';
	printf("Enter no of vertices: ");
	scanf("%d",&m);
	printf("Enter no of edges: ");
	scanf("%d",&n);
	int adjmat[m][m];
	for(i=0;i<m;i++)
	{
		adjmat[i][i]=0;
		for(j=i+1;j<m;j++)
		{
			printf("Is there an edge between vertices %d and %d?(y/n)\n",i+1,j+1);
			scanf(" %c",&ch);
			if(ch=='y')
				adjmat[i][j]=adjmat[j][i]=1;
			else
				adjmat[i][j]=adjmat[j][i]=0;
		}
	}

	nodeptr adjlist[m];
	for(i=0;i<m;i++)
	{
		adjlist[i]=addNode(i+1);
		nodeptr temp=adjlist[i];
		for(j=0;j<m;j++)
		{
			if(adjmat[i][j]){
				temp->link=addNode(j+1);
				temp=temp->link;
			}
		}
	}

	printf("\nAdjacency Matrix:\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<m;j++)
			printf("%d\t",adjmat[i][j]);
		printf("\n");
	}

	printf("\nAdjacency List:\n");
	for(i=0;i<m;i++)
	{
		printf("Vertex %d:\n",i+1);
		displayList(adjlist[i]);
	}
}