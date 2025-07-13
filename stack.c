#include<stdio.h>
#include "ststack.h"
int main()
{
    struct stack s;
    int opt,x,n,e;
    inits(&s);
    do
      {
          printf("1.Push\n2.Pop\n3.Peek\n4.isEmpty\n5.isfull\n6.Exit\n");
          scanf("%d",&opt);
          switch(opt)
          {
            case 1:printf("enter element to push\n");
            scanf("%d",&x);
            pushs(&s,x);
            break;
            case 2:e=pops(&s);
                   if(e!=0)
                   {
                      printf("deleted element is %d\n",e);
                   }
                   else
                   printf("stackis underflow\n");
                   break;
            case 3:e=peeks(&s);
                   printf("element on top is %d\n",e);
                   break;
                   
            case 4:e=isemptys(&s);
                   if(e==1)
                   printf("list is empty\n");
                   else
                   printf("list is nnot empty\n");
                   break;
            case 5:e=isfulls(&s);
                   if(e==1)
                   printf("list is full\n");
                   else
                   printf("list is not full\n");
                   break;
        }
     }while(opt!=6);
     return 0;
}
void inits(struct stack *ps)
{
  ps->top=-1;
}
void pushs(struct stack *ps,int x)
{
   if((isfulls(ps))==1)
   {
      printf("stack overflow\n");
      return;
   }
   else
   {
     ps->a[++ps->top]=x;
   }
}
int pops(struct stack *ps)
{
   if((isemptys(ps))==1)
   return 0;
   else
   {
      return ps->a[ps->top--];
   }
}
int peeks(struct stack *ps)
{
   return ps->a[ps->top];
}
int isemptys(struct stack *ps)
{
   if(ps->top==-1)
   return 1;
   else
   return 0;
}
int isfulls(struct stack *ps)
{
   if(ps->top==MAX-1)
   return 1;
   else
   return 0;
}
  
                 
          
