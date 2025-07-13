#include <stdio.h>
void main()
{
  int n, a[100], i,j,temp;

  printf("Enter number of elements\n");
  scanf("%d", &n);

  printf("Enter elements:\n");
  for(i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
   }

  for (i= 1; i <n; i++) 
  {
      temp=a[i];
      j=i-1;
      while(j>=0 && a[j]>temp)
       {
          a[j+1]=a[j];
          j = j - 1;
      }
   a[j+1]=temp;
}
  printf("Sorted list in ascending order:\n");

  for (i = 0; i<n; i++) 
  {
    printf("%d\n", a[i]);
  }

  
}
