#include<stdio.h>
#include<stdlib.h>
#include "dystack.h"
int main()
{
   struct stack *s,*e;
   int ch,x,n;
   init(&s);
   do
   {
      printf("1.push\n2.Pop\n3.Peek\n4.isempty\n5.Exit\n");
      scanf("%d",&ch);
      switch(ch)
      {
         case 1:printf("enter element to push\n");
                scanf("%d",&x);
                push(&s,x);
                break;
         case 2:e=pop(&s);
                if(e!=NULL)
                {
                   free(e);
                   peek(s);
                }
               else
               printf("stack is underflow\n");
               break;
         case 3:peek(s);
                break;
         case 4:isempty(s);
                break;
        }
     }while(ch!=5);
     return 0;
}
void init(struct stack **s)
{
   *s=NULL;
}
void push(struct stack **s,int x)
{
   struct stack *p;
   p=(struct stack *)malloc(sizeof(struct stack));
   p->info=x;
   p->next=NULL;
   if(*s==NULL)
   {
     *s=p;
   }
   else
   {
      p->next=*s;
      *s=p;
   }
}
display(struct node **l)
{
   struct stack *p;
   if(*l==NULL)
   {
      printf("List is empty\n");
   }
   else
   {
      p=*l;
      while(p!=NULL)
      {
         printf("%d\t",p->info);
         p=p->next;
      }
   }
}
struct stack* pop(struct stack **s)
{
  struct stack *p;
  if(*s==NULL)
  return NULL;
  else
  {
    p=*s;
    *s=(*s)->next;
    p->next=NULL;
    return p;
  }
}
void peek(struct stack *s)
{
  if(s==NULL)
  printf("stak underflow\n");
  else
  printf("%d\n",s->info);
}
void isempty(struct stack *s)
{
  if(s==NULL)
  printf("List is empty\n");
  else
  printf("list is not empty\n");
}

  
     
