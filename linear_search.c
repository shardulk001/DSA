#include<stdio.h>
void main()
{
   int a[100];
   int n,i,s,flag=0;
   printf("enter how many elements");
   scanf("%d",&n);
   printf("enter the %d elements:\n",n);
   for(i=0;i<n;i++)
    {
       scanf("%d",&a[i]);
    }
  printf("enter the elment to be search");
  scanf("%d",&s);
  for(i=0;i<n;i++)
  {
     if(a[i]==s)
      {
         flag=1;
         break;
      }
   }
   
   if(flag==1)
   printf("%d element is found at %d position",s,i+1);
   else
   printf("element is not found");
}
