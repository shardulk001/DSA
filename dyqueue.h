struct node
{
    int data;
    struct node *link;
}*front, *rear;
void insert();
void delete();
void queue_size();
void check();
void first_element();
void insert()
{
    struct node *temp;

    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter value to be inserted \n");
    scanf("%d", &temp->data);
    temp->link = NULL;
    if (rear  ==  NULL)
    {
        front = rear = temp;
    }
    else
    {
        rear->link = temp;
        rear = temp;
    } 
}
void delete()
{
    struct node *temp;

    temp = front;
    if (front == NULL)
    {
        printf("queue is empty \n");
        front = rear = NULL;
    }
    else
    { 
        printf("deleted element is %d\n", front->data);
        front = front->link;
        free(temp);
    }
}
void check()
{
    if (front == NULL)
        printf("\nQueue is empty\n");
    else
        printf("*************** Elements are present in the queue **************\n");
}
void first_element()
{
    if (front == NULL)
    {
        printf("**************** The queue is empty ****************\n");
    }
    else
        printf("**************** The front element is %d ***********\n", front->data);     
}
void queue_size()
{
    struct node *temp;

    temp = front;
    int cnt = 0;
    if (front  ==  NULL)
    {
        printf(" queue empty \n");
    }
    while (temp)
    {
        printf("%d  ", temp->data);
        temp = temp->link;
        cnt++;
    }
    printf("********* size of queue is %d ******** \n", cnt);
}

