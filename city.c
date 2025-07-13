//Reading from file

#include<stdio.h>
#include<string.h>

int linearsearch(int n);
typedef struct city
{
    char name[20];
    int code;
} city;

//Fileread
int fileread(city a[20])
{
   FILE *fp;
   int i=0;
   fp=fopen("cities.txt","r");
   if(fp==NULL)
   printf("File Not Exist");
   else
    {
     while(!feof(fp))
      {
       fscanf(fp,"%s%d", a[i].name, &a[i].code);
       i++;
      }
      fclose(fp);
    }
  return i-1;
}

//Main
int main()
{
   int i, n;
   char key[20];
   city a[20];
   n = fileread(a);
   for(int i=0; i<n; i++)
   printf("%s %d\n", a[i].name, a[i].code);   /* displaying records*/
   linearsearch(n);   // function declaration
}

//Linear Search
int linearsearch(int n)
{
  city a[20];
  n=fileread(a);
  char str[20];
  int index,flag=0;
  printf("Enter city:");
  scanf("%s",str);
  for(int i=0;i<n;i++)
  {
    if(strcmp(str,a[i].name)==0)
     {
       flag=1;
       index=i;
     }
   }

if(flag==1)
printf("City Code: %d",a[index].code);
else
printf("City Not in list");
}
