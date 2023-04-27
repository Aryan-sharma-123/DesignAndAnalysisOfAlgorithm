#include<stdio.h>
#include<stdlib.h>
int small(int a, int b)
{
    if(a<b)
    {
       return a;
    }
   else
    {
       return b;
    }
}

int gcd(int a,int b,int c)
{
  int count=0;
  int q=a;
  while(q>0)
  {
    count ++;
    if( b%q == 0 && c%q == 0)
     {
       break;
     }
    else
     {
        q--;
     }

  }
  printf("the number of counts are: %d\n",count);
     printf("\nThe gcd of the two numbers entered by you is: \n");
  return q;
}
int main()
{
  unsigned int a,b;

   printf("Enter any two numbers to find the gcd of the two ! ");
   scanf("%d%d",&a,&b);

   printf("\nThe smallest of the two numbers entered by you is: \n");
   printf("%d",small(a,b));

   int c=small(a,b);
   gcd(c,a,b);


   printf("%d",gcd(c,a,b));

   return 0;
}
