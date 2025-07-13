#define MAX 10
struct stack
{
     int a[MAX];
     int top;
};
void inits(struct stack*);
void pushs(struct stack*,int);
int pops(struct stack*);
int isfulls(struct stack*);
int isemptys(struct stack*);
int peeks(struct stack*);
