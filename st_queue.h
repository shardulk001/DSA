#define MAXSIZE 30
typedef struct queue
{
int data[MAXSIZE];
int front,rear;
}QUEUE;
void initqueue(QUEUE *pq)
{
pq->front=pq->rear=-1;
}
int isfull(QUEUE *pq)
{
if(pq->rear==MAXSIZE-1)
return 1;
return 0;
}
int isempty(QUEUE *pq)
{
return(pq->front==pq->rear);
}
void addq(QUEUE *pq, int num)
{
pq->data[++pq->rear]=num;
}
int removeq(QUEUE *pq)
{
int num;
++pq->front;
num=pq->data[pq->front];
return num;
//return pq->data[++pq->front];
}
int peek(QUEUE *pq)
{
    int num;
    ++pq->front;
    num=pq->data[pq->front];
    return num;
}

