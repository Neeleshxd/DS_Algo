#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int queue[MAX];
int front=-1,rear=-1;
void enqueue();
void dequeue();
void display();
int main()
{
    int ch;
    while(1)
    {
        printf("\n1.enqueue\n2.dequeue\n3.Display\n4.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:enqueue();
                   break;
            case 2:dequeue();
                   break;
            case 3:display();
                   break;
            case 4:exit(0);
            default:printf("Invalid choice\n");
        }
    }
}
void enqueue()
{
    int item;
    if((front==0 && rear==MAX-1) || (front==rear+1))
    {
        printf("Queue Overflow\n");
        return;
    }
    printf("Enter the element to be enqueueed:");
    scanf("%d",&item);
    if(front==-1)
    {
        front=0;
        rear=0;
    }
    else
    {
        if(rear==MAX-1)
            rear=0;
        else
            rear=rear+1;
    }
    queue[rear]=item;
}
void dequeue()
{
    if(front==-1)
    {
        printf("Queue Underflow\n");
        return;
    }
    printf("The dequeued element is %d\n",queue[front]);
    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else
    {
        if(front==MAX-1)
            front=0;
        else
            front=front+1;
    }
}
void display()
{
    int i;
    if(front==-1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("The elements of the queue are:\n");
    if(front<=rear)
    {
        for(i=front;i<=rear;i++)
            printf("%d\t",queue[i]);
    }
    else
    {
        for(i=front;i<=MAX-1;i++)
            printf("%d\t",queue[i]);
        for(i=0;i<=rear;i++)
            printf("%d\t",queue[i]);
    }
    printf("\n");
}
