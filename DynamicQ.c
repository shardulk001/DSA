/*Q. Implement a queue library (dyqueue.h) of integers using a dynamic (circular linked list) implementation of the queue and implementing the above five operations. Write a driver program that includes queue library and calls different queue operations.*/
#include <stdio.h>
#include <stdlib.h>
#include "dyqueue.h"
#define MAX 10
void main()
{
    int choice, value;

    while(1)
    {
        printf("enter the choice \n");
        printf("1 : display size of queue \n2 : Insert element\n");
        printf("3 : Dequeue an element \n4 : Check if empty\n");
        printf("5. Get the first element of the queue\n");
        printf("6. Get the number of entries in the queue\n");
        printf("7. Exit\n");
        scanf("%d", &choice);
        switch (choice) 
        {
        case 1:
            printf("queue is created with a capacity of %d\n", MAX);
            break;
        case 2: 
            insert();
            break;
        case 3:
            delete();
            break;
        case 4:
            check();
            break;
        case 5:
            first_element();
            break;
        case 6:
            queue_size();
            break;
        case 7:
            exit(0);
        default:
            printf("wrong choice\n");
            break;
        }
    }
}

