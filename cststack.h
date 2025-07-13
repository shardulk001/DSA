#define MAX 30
struct stack
{
char a[MAX];
int top;
};

void initc(struct stack *);
void pushc(struct stack *,char[],int);
char popc(struct stack *);
int isfullc(struct stack *);
int isemptyc(struct stack *);

