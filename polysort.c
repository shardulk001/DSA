[n#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *next;
	};
void insertAtTheBegin(struct Node **start_ref,int data);

void bubbleSort(struct Node *start);
void swap(struct Node *a,struct Node *b);
void printList(struct Node *start);

int main()
{
	int arr[]={12,56,2,11,1,90};
	int list_size, i;
	struct Node *start=NULL;
	
	for(i=0;i<6;i++)
	insertAtTheBegin(&start,arr[i]);
	printf("\n Linked list before sorting");
	printList(start);
	
	bubbleSort(start);
	
	printf("\n Linked list after sorting");
	printList(start);
	
	getchar();
	return 0;
}

void insertAtTheBegin(struct Node **start_ref,int data)
{
struct Node *ptr1=(struct Node*)malloc(sizeof(struct Node));
ptr1->data = data;
ptr1->next = *start_ref;
*start_ref= ptr1;
}

void printList(struct Node *start)
{
	struct Node *temp = start;
	printf("\n");
	while(temp!=NULL)
	{
		printf("%d  ",temp->data);
		temp = temp->next;
		}
		}
void bubbleSort(struct Node *start)
{
	int swapped, i;
	struct Node *ptr1;
	struct Node *lptr = NULL;
	
	if (start == NULL)
	return;
	
	do
	{
		swapped = 0;
		ptr1 = start;
		while(ptr1->next!=lptr)
		{
			if (ptr1->data > ptr1->next->data)
			{
				swap(ptr1, ptr1->next);
				swapped =1;
				}
			ptr1=ptr1->next;
			}
			lptr = ptr1;
		}
	while (swapped);
}

void swap(struct Node *a,struct Node *b)
{
	int temp = a->data;
	a->data = b->data;
	b->data = temp;
} 
