#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};
void insert(struct node **head,int data)
{
struct node *newnode;
newnode=malloc(sizeof(struct node));
newnode->data=data;
newnode->next=NULL;
if(*head==NULL)
*head=newnode;
else
{
struct node *temp=*head,*prev;
while(temp)
{
if(temp->data >=data)
{
if(temp==*head)
{
newnode->next=*head;
*head=newnode;
}
else
{
prev->next=newnode;
newnode->next=temp;
}
break;
}
else
{
prev=temp;
temp=temp->next;
}
}
if(!temp)
prev->next=newnode;
}
}
void display(struct node *temp)
{
if(!temp)
printf("\n\tEmpty list\n");
else
{
while(temp)
{
printf("\t%d ",temp->data);
temp=temp->next;
}
}
}
void search(struct node *head , int data)
{
struct node *temp= head;
int cnt=0;
while(temp && temp->data != data)
{
temp=temp->next;
cnt++;
}
if(temp)
printf("%d is at %d position\n",data,cnt);
else
printf("No data\n");
getchar();getchar();
}
int menu()
{
system("clear");
int ch;
printf("\n\t0.Exit\n\t1.Create list\n\t2.Display list\n\t3.Search node \n\tEnter your choice :");
scanf("%d",&ch);
return ch;
}
main()
{
struct node *head=NULL;
int ch;
while((ch=menu())!=0)
{
if(ch==1)
{
int i,size;
printf("How many nodes you want :");
scanf("%d",&size);
for(i=0;i<size;i++)
insert(&head,random()%100);
}
else
if(ch==2)
{
display(head);
getchar();getchar();
}
else
if(ch==3)
{
int i,node;
printf("Enter node to be searched :");
scanf("%d",&node);
search(head,node);
getchar();getchar();
}
}
}
