#include <stdio.h>
void main()
{
    int a[10];
    int i, j, num, temp;

    printf("Enter the value of num \n");
    scanf("%d", &num);
    printf("Enter the elements one by one \n");
    for (i = 0; i <num; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Input array is \n");
    for (i = 0; i <num; i++)
    {
        printf("%d\n", a[i]);
    }
    
   for(i=0; i<num-1; i++)
   {
        for(j=0; j<num-i-1; j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    printf("Sorted array is...\n");
    for (i = 0; i <num; i++)
    {
        printf("%d\n", a[i]);
    }
}
    
    
    
