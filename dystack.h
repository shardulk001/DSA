struct stack
{
   int info;
   struct stack *next;
};
void init(struct stack**);
void push(struct stack**,int);
struct stack * pop(struct stack**);
void peek(struct stack*);
void isempty(struct stack*);
void display(struct stack);

