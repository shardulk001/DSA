#include<stdio.h>
void quicksort(int[],int,int);
void main()
{
    int low,high,pivot,t,n,i,j,a[10];
    printf("\n enter the size of array:");
    scanf("%d",&n);
    printf("\n enter the elements:");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    low=0;
    high=n-1;
    quicksort(a,low,high);
    printf("\n After sorting the elements are:");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
}
void quicksort(int a[],int low,int high)
{
     int pivot,t,i,j;
     if(low<high)
     {
        pivot=a[low];
        i=low+1;
        j=high;
        while(i<j)
        {
            while(pivot>=a[i]  &&  i<=high)
            i++;
            while(pivot<a[j] && j>=low)
            j--;
            if(i<j)
            {
                 t=a[i];
                 a[i]=a[j];
                 a[j]=t;
            }
        }
        a[low]=a[j];
        a[j]=pivot;
        quicksort(a,low,j-1);
        quicksort(a,j+1,high);
     }
}    
        
    
