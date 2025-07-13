#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct employee
{
char name[20];
};
void insertsort(struct employee emp[],int num)
{
struct employee temp;
int i,j;
for(i=1;i<num;i++)
{
temp=emp[i];
for(j=i-1;j>=0 && strcmp(emp[j].name,temp.name)>0;j--)
{
emp[j+1]=emp[j];
}
emp[j+1]=temp;
}
}
 void main()
{
struct employee *emp=NULL,temp;
FILE *fp;
int i,j,num;
char name[20];
fp=fopen("emp.txt","r");
while(fscanf(fp,"%s",name)!=EOF)
num++;
emp=malloc(sizeof(struct employee)*num);
num=0;
rewind(fp);
while(fscanf(fp,"%s",emp[num].name)!=EOF)
num++;
fclose(fp);
insertsort(emp,num);
fp=fopen("emp.txt","w");
for(i=0;i<num;i++)
fprintf(fp,"%s\n",emp[i].name);
fclose(fp);
}
