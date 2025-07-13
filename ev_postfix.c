#include<stdio.h>
#include<ctype.h>
int stack[20];
int top=-1;
void push(int x)
{
 stack[++top]=x;
}

int pop()
{
  return stack[top--];
}

int main()
{
  char exp[20];
  setbuf(stdout,NULL);
  char *temp;
  int n1,n2,n3,num;
  printf("enter postfix expression without space::");
  scanf("%s",exp);
  temp=exp;
  while(*temp!='\0')
  {
    if(isdigit(*temp))
    {
     num=*temp-48;
     push(num);
    }
    
    else
    {
      n1=pop();
      n2=pop();
      switch(*temp)
      {
        case '+':
        {
          n3=n2+n1;
          break;
         }
         
        case '-':
        {
          n3=n2-n1;
          break;
         }
         case '*':
        {
          n3=n2*n1;
          break;
         }
         
        case '/':
        {
          n3=n2/n1;
          break;
         }
       }
       push(n3);
     }
     temp++;
   }
   
   printf("\n The result of postfix expression %s=%d\n\n",exp,pop());
   return 0;
 }
          
      
