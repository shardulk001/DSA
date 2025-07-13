#include<stdio.h>
#include<string.h>
#include "cststack.h"
int reverse(struct stack *, char[], int);

int main()
{
struct stack s;
char ch[MAX],e;
int n=0,i,p;
initc(&s);
printf("enter a string to push \n");
gets(ch);
while(ch[n]!='\0')
{
n++;
}

printf("total char is %d\n",n);
pushc(&s,ch,n);
p=reverse(&s,ch,n);
if(p!=0)
  printf("it is palandrome\n");
  
  else
  printf("not a palindrome\n");
  
  return 0;
  
  }
  
void initc(struct stack *cs)
{ 
 cs->top=-1;
}

void pushc(struct stack *cs, char ch[], int n)
{

 int i; 
 if(isfullc(cs))
 {
   printf("stack overflow\n");
   return ;
   
   }
   else
   {
    for(i=0;i<=n;i++)
    cs->a[++cs->top]=ch[i] ;
    }
 }
 
 char popc(struct stack *cs)
 {
  if(isemptyc(cs))
  {
   return 0;
   }
   else
   {
   return cs->a[cs->top--];
   }
  } 
  
  int isemptyc(struct stack *cs)
  {
  if(cs->top==-1)
  return 1;
  
  else
  return 0;
  }
     
  int isfullc(struct stack *cs)
  {
   if(cs->top==MAX-1)
   return 1;
   
   else 
    return 0;
    
    }
   
  
int reverse(struct stack *cs, char ch[], int n)
{
 int i=0;
 if(isemptyc(cs))
 {
 return 0;
 }
 cs->top=cs->top-1;
 while(cs->top!='\0' && i<n)
 {
  if(cs->a[cs->top]==ch[i])
  {i++;
  cs->top=cs->top-1;
  continue;
  }
  else
  return 0;
  }

  return 1;
  }
  
