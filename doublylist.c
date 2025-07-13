#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
void create();
void insert_at_beg();
void insert_at_end();
void insert_after_pos();
void del();
void display();
struct node
{
    int info;
    struct node *next;
    struct node *prev;
}*start=NULL;
int data,item,n1,pos,i,m;
int main()
{
    int ch;
    setbuf(stdout,NULL);
    printf("\n **Linked List**\n");
    printf("\n1.create\n2.Insert at beginning\n3.Insert at End\n4.Insert after position\n5.delete\n6.display\n7.Exit\n");
while(1)
 {
         printf("\n Enter your choice:\n");
         scanf("%d",&ch);
         switch(ch)
         {
           case 1:create();
                 break;
           case 2:insert_at_beg();
                  break;
           case 3:insert_at_end();
                  break;
           case 4:insert_after_pos();
                  break;
           case 5:del();
                  break;
           case 6:display();
                  break;
           case 7:exit(0);
           default:printf("\nWrong choice!!\n");
           }
  }
  return 0;
}
void create()
{
  int data;
  struct node *tmp;
  printf("enter the first element to be inserted:\n");
  scanf("%d",&data);
  tmp=malloc(sizeof(struct node));
  tmp->info=data;
  tmp->prev=NULL;
  tmp->next=NULL;
  if(start==NULL)
    start=tmp;
  display();
}
 
void insert_at_beg()
{
    int data;
    struct node *tmp;
    printf("\n enter the element to be inserted:\n");
    scanf("%d",&data);
    tmp=malloc(sizeof(struct node));
    tmp->info=data;
    tmp->prev=NULL;
    tmp->next=NULL;
    if(start==NULL)
       start=tmp;
    else
    {
       start->prev=tmp;
       tmp->next=start;
       start=tmp;
    }
    display();
}

void insert_at_end()
{
    int data;
    struct node *q,*tmp;
    printf("\nEnter the lement to be inserted:\n");
    scanf("%d",&data);
    tmp=malloc(sizeof(struct node));
    tmp->info=data;
    tmp->prev=NULL;
    tmp->next=NULL;
    if(start==NULL)
        start=tmp;
    else
    {
      q=start;
      while(q->next!=NULL)
      q=q->next;   //go to last node
      q->next=tmp;
      tmp->prev=q;
   }
   display();
}
void insert_after_pos()
{
   int data;
   struct node *q,*tmp;
   tmp=malloc(sizeof(struct node));
   printf("\nEnter the element to be inserted:\n");
   scanf("%d",&data);
   tmp->info=data;
   tmp->prev=NULL;
   tmp->next=NULL;
   if(start==NULL)
   {
      start=tmp;
   }
   else
   {
      printf("Enter index after which element to be inserted:\n");
      scanf("%d",&pos);
      q=start;
      for(i=0;i<pos;i++)
      {
         q=q->next;
      }
      tmp->next=q->next;
      if(q->next!=NULL)
      {
         q->next->prev=tmp;
      }
      q->next=tmp;
      tmp->prev=q;
      display();
    }
}

void del()
{
    struct node *tmp,*q,*prev;
    printf("enter the element to be deleted:\n");
    scanf("%d",&data);
    if(start->info==data)   //deletion of first node
    {
       tmp=start;
       if(tmp->next!=NULL)
       {
         start->next->prev=NULL;
       }
       start=start->next;
       free(tmp);
       display();
       return;
    }
    q=start;
    while(q->next->next!=NULL)   //deletion of middle node
    {
       if(q->next->info==data)
       {
          prev=q->next->prev;
          tmp=q->next;
          q->next=tmp->next;
          q->next->prev=prev;
          free(tmp);
          display();
          return;
        }
        q=q->next;
     }
     if(q->next->info==data)    //deletion at end
     {
        tmp=q->next;
        q->next=NULL;
        free(tmp);
        display();
        return;
     }
     printf("\nElement not found\n");
}
void display()
{
   struct node *q;
   if(start==NULL)
     printf("List is empty!!\n");
     else
     {
        printf("***Element in doubly linked list***\n");
        q=start;
        while(q!=NULL)
        {
           printf("%d\t",q->info);
           q=q->next;
        }
     }
}


