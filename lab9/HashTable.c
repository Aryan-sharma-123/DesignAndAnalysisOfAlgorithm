#include <stdio.h>
#include <stdlib.h>

#define size 7

 struct node 
 {
    int data;
    struct node *next;
 };

struct node *chain[size];

void init();
int insert(int value);
int search(int value);
void print(); 

int main() 
{
    init();

    int num_elements;
    printf("Enter the number of elements to insert: ");
    scanf("%d", &num_elements);
    
    int i, value, comparisons;
  
    for (i = 0; i < num_elements; i++) 
    {
        printf("Enter a value to insert: ");
        scanf("%d", &value);
        comparisons = insert(value);
        printf("Inserted %d with %d key comparisons\n", value, comparisons);
    }
  
    print();
  
    int search_value;
    printf("Enter a value to search for: ");
    scanf("%d", &search_value);
    comparisons = search(search_value); 

    if (comparisons == 1)
    { 
        printf("%d not found with %d key comparison\n", search_value, comparisons);
    }

    else
    {
        printf("%d found with %d key comparisons\n", search_value, comparisons);
    }

    return 0;
}

void init() 
{
    int i;
    for (i = 0; i < size; i++) 
    {
        chain[i] = NULL;
    }
}

int insert(int value) 
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    
    int key = value % size;
    int comparisons = 0;
    
    if (chain[key] == NULL) 
    {
        chain[key] = newNode;
        comparisons = 1;
    } 
    else 
    {
        struct node *temp = chain[key];

        while (temp->next) 
        {
            temp = temp->next;
            comparisons++;
        }

        temp->next = newNode;
        comparisons++;
    }

    return comparisons;
}

int search(int value) 
{
    int key = value % size;
    int comparisons = 0;
  
    struct node *temp = chain[key];

    while (temp) 
    {
        comparisons++;
        if (temp->data == value)
        return comparisons;
        temp = temp->next;
    }

    return comparisons;
}

void print() 
{
    int i;

    for (i = 0; i < size; i++) 
    {
        struct node *temp = chain[i];
    
        printf("chain[%d]-->", i);
    
        while (temp) 
        {
            printf("%d -->", temp->data);
            temp = temp->next;
        }
    
        printf("NULL\n");
    }
}
