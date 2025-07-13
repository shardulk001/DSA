#include<stdio.h>
#include<stdlib.h>
#define newnode (struct snode*)malloc(sizeof(struct snode))
struct snode
{
                int data;
                struct snode *next;
};
struct snode *create(int no)
{
                struct snode *f,*s;
                int i;
                f=newnode;
                printf("enter data");
                scanf("%d",&f->data);
                f->next=NULL;
                s=f;
                for(i=2;i<=no;i++)
                {
                s->next=newnode;
                s=s->next;
                scanf("%d",&s->data);
                s->next=NULL;
                }
                s->next=f;
                return f;
}          
void display(struct snode *f)
{
                struct snode *s;
                s=f;
                do
                {printf("\t%d",s->data);
                s=s->next;
                }while(s!=f);
}

struct node * append(struct snode *f,int n)
{              struct snode *t,*s;
                s=newnode;
                s->data=n;
                t=f;
                int i,count=0;
                do
                {              count++;
                                t=t->next;
                } while(t->next!=f);
                t->next=s;
                t=t->next;
                t->next=f;
                return f;
}

main()
{              int no,num;
                struct snode *l1,*l2;
                printf("enter no of nodes for 1st link");
                scanf("%d",&no);
                l1=create(no);
                display(l1);
                printf("\nenter data to be append : ");
                scanf("%d",&num);
                l1=append(l1,num);
                display(l1);
}
