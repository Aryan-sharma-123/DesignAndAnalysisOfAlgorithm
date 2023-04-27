#include<stdio.h>
#include<stdlib.h>

struct node
{
 int data ;
 struct node *left;
 struct node *right;
};

 int flag;

struct node *newnode(int data)
{
  struct node *node = (struct node * )malloc(sizeof(struct node));

  node->data=data;
  node->left=NULL;
  node->right=NULL;

  return (node);
}

void displayinorder(struct node *root )
{
  if(root!=NULL)
  {
    displayinorder(root->left);
    printf("%d\t",root->data);
    displayinorder(root->right);
  }
}

void displaypostorder(struct node *root)
{
  if(root!=NULL)
  {
  displaypostorder(root->left);
  displaypostorder(root->right);
  printf("%d\t",root->data);
  }

}

void displaypreorder(struct node *root)
{

   if(root!=NULL)
   {
     printf("%d\t",root->data);
     displaypreorder(root->left);
     displaypreorder(root->right);
    }

}



void inorder_search( struct node *root,int value)
{
   if(!root)
   {
    return ;
   }
   inorder_search(root->left,value);

   if(root->data == value )
   {
   printf("\nThe element is found in the binary tree\n");
   flag=1;
   }

   inorder_search(root->right,value);
}

 void insert(struct node **root,int value)
 {
    if(*root == NULL)
    {
    *root=newnode(value);
    return ;
    }
    if(value<(*root)->data)
    {
    insert(&(*root)->left,value);
    }
    else
    {
      insert(&(*root)->right,value);
    }
 }

int main()
{
 struct node *root ;
 int ele;

 insert(&root,90);
 insert(&root,67);
 insert(&root,78);
 insert(&root,45);
 insert(&root,80);
 insert(&root,17);
 insert(&root,75);
 insert(&root,89);

 printf("Enter the value to be searched: \n");
 scanf("%d",&ele);
 inorder_search(root,ele);

 if(flag == 0)
 {
 printf("\nThe element is not present in the binary tree, hence the system have to insert it ! \n\n  ");
 insert(&root,ele);
 }

 printf("The inoder traversal of binary tree is: \n");
 displayinorder(root);

 printf("\nThe postorder traversal of binary tree is: \n");
 displaypostorder(root);

 printf("\nThe preorder traversal of binary tree is: \n");
 displaypreorder(root);
 return 0;
}
