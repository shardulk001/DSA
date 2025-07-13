/*Operations on singly linked list - Create, Insert,Delete,Search */

#include<stdio.h>

#include<stdlib.h>
typedef struct node
   { int data;
     struct node *next;
   }node;

node *create();
node *delete_b(node *head);
node *delete_e(node *head);
node *delete_in(node *head);
void print(node *head);

void main()
{
  int op,op1,x;
  node *head=NULL;
  
  do
    {
      printf("\n\n1)create\n2)Delete\n3)Print4)Quit");
      printf("\n5)Print\n6)Quit");
      printf("\nEnter your Choice:");
      scanf("%d",&op);
      switch(op)
       {
	 case 1:head=create();break;
	
	 case 2:printf("\n\t1)Beginning\n\t2)End\n\t3)In between");
		printf("\nEnter your choice : ");
		scanf("%d",&op1);
		switch(op1)
		 {  case 1:head=delete_b(head);
			   break;
		    case 2:head=delete_e(head);
			   break;
		    case 3:head=delete_in(head);
			   break;
		  }
		 break;
	 case 3:print(head);break;
	 case 4:exit(0);
       }
    }while(op!=5);
}

node *create()
{
	node *head,*p;
	int i,n;
	head=NULL;
	printf("\n Enter no of data:");
	scanf("%d",&n);
	printf("\nEnter the data:");
	for(i=0;i<n;i++)
	    {
		if(head==NULL)
			p=head=(node*)malloc(sizeof(node));
		else
		   {
			p->next=(node*)malloc(sizeof(node));
			p=p->next;
		   }
		p->next=NULL;
		scanf("%d",&(p->data));
	    }
	return(head);
}

node *delete_b(node *head)
{
	node *p,*q;
	if(head==NULL)
	   {
		printf("\nUnderflow....Empty Linked List");
		return(head);
	   }
	p=head;
	head=head->next;
	free(p);
	return(head);

}
node *delete_e(node *head)
{
	node *p,*q;
	if(head==NULL)
	   {
		printf("\nUnderflow....Empty Linked List");
		return(head);
	   }
	p=head;
	if(head->next==NULL)
	   { // Delete the only element
		head=NULL;
		free(p);
		return(head);
	   }
	//Locate the last but one node
	for(q=head;q->next->next !=NULL;q=q->next)
	;
	p=q->next;
	q->next=NULL;
	free(p);
	return(head);
}

node *delete_in(node *head)
{
	node *p,*q;
	int x,i;
	if(head==NULL)
	   {
		printf("\nUnderflow....Empty Linked List");
		return(head);
	   }
	printf("\nEnter the data to be deleted : ");
	scanf("%d",&x);
	if(head->data==x)
	    { // Delete the first element
		p=head;
		head=head->next;
		free(p);
		return(head);
	    }
	//Locate the node previous to one to be deleted
	for(q=head;q->next->data!=x && q->next !=NULL;q=q->next )
	;
	if(q->next==NULL)
	    {
		printf("\nUnderflow.....data not found");
		return(head);
	    }
	p=q->next;
	q->next=q->next->next;
	free(p);
	return(head);
}

void print(node *head)
{
	node *p;
	printf("\n\n");
	for(p=head;p!=NULL;p=p->next)
		printf("%d  ",p->data);
}

/*


OUTPUT:


1)create
2)Insert
3)Delete
4)Search
5)Print
6)Quit
Enter your Choice:1

 Enter no of data:4

Enter the data:1 2 3 4

1)create
2)Insert
3)Delete
4)Search
5)Print
6)Quit
Enter your Choice:5

1  2  3  4

1)create
2)Insert
3)Delete
4)Search
5)Print
6)Quit
Enter your Choice:2

        1)Beginning
        2)End
        3)In between
Enter your choice : 1

Enter the data to be inserted : 0

1)create
2)Insert
3)Delete
4)Search
5)Print
6)Quit
Enter your Choice:2

        1)Beginning
        2)End
        3)In between
Enter your choice : 2

Enter the data to be inserted : 5

1)create
2)Insert
3)Delete
4)Search
5)Print
6)Quit
Enter your Choice:2

        1)Beginning
        2)End
        3)In between
Enter your choice : 3

Enter the data to be inserted : 44
Insert after which number ? : 4


1)create
2)Insert
3)Delete
4)Search
5)Print
6)Quit
Enter your Choice:5
0  1  2  3  4  44  5

1)create
2)Insert
3)Delete
4)Search
5)Print
6)Quit
Enter your Choice:3

        1)Beginning
        2)End
        3)In between
Enter your choice : 1

1)create
2)Insert
3)Delete
4)Search
5)Print
6)Quit
Enter your Choice:3

        1)Beginning
        2)End
        3)In between
Enter your choice : 2


1)create
2)Insert
3)Delete
4)Search
5)Print
6)Quit
Enter your Choice:3

        1)Beginning
        2)End
        3)In between
Enter your choice : 3

Enter the data to be deleted : 44

1)create
2)Insert
3)Delete
4)Search
5)Print
6)Quit
Enter your Choice:5

1  2  3  4

1)create
2)Insert
3)Delete
4)Search
5)Print
6)Quit
Enter your Choice:4

Enter the data to be searched: 4

Found at location=4

1)create
2)Insert
3)Delete
4)Search
5)Print
6)Quit
Enter your Choice:6

*/
