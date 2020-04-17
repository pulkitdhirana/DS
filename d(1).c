#include<stdio.h>
#include<stdlib.h>
#define MAX 7
int s[MAX];
int front=-1;
int rear=-1;
void ins front(int item);
void insert_rearEnd(int item);
int delete_frontEnd();
int delete_rearEnd();
void display();
int isEmpty();
int isFull();

main()
{
    int choice,item;
    while(1)
    {
        printf("1.Insert at the front end\n");
        printf("2.Insert at the rear end\n");
        printf("3.Delete from front end\n");
        printf("4.Delete from rear end\n");
        printf("5.Display\n");
        printf("6.Quit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            printf("Input the element for adding in queue : ");
            scanf("%d",&item);
            ins front(item);
            break;
        case 2:
            printf("Input the element for adding in queue : ");
            scanf("%d",&item);
            insert_rearEnd(item);
            break;
         case 3:
            printf("Element deleted from front end is : %d\n",delete_frontEnd());
            break;
         case 4:
            printf("Element deleted from rear end is : %d\n",delete_rearEnd());
            break;
         case 5:
            display();
            break;
         case 6:
            exit(1);
         default:
            printf("Wrong choice\n");
        }/*End of switch*/
        printf("front = %d, rear =%d\n", front , rear);
        display();
    }/*End of while*/
}/*End of main()*/

void ins front(int item)
{
    if( isFull() )
    {
        printf("Queue Overflow\n");
        return;
    }
    if( front==-1 )/*If queue is initially empty*/
    {
        front=0;
        rear=0;
    }
    else if(front==0)
        front=MAX-1;
    else
        front=front-1;
    s[front]=item ;
}
void insert_rearEnd(int item)
{
    if( isFull() )
    {
        printf("Queue Overflow\n");
        return;
    }
    if(front==-1)  /*if queue is initially empty*/
    {
        front=0;
        rear=0;
    }
    else if(rear==MAX-1)  /*rear is at last position of queue */
        rear=0;
    else
        rear=rear+1;
    s[rear]=item ;
}/*End of insert_rearEnd()*/

int delete_frontEnd()
{
    int item;
    if( isEmpty() )
    {
        printf("Queue Underflow\n");
        exit(1);
    }
    item=s[front];
    if(front==rear) /*Queue has only one element */
    {
        front=-1;
        rear=-1;
    }
    else
        if(front==MAX-1)
            front=0;
        else
            front=front+1;
    return item;
}/*End of delete_frontEnd()*/

int delete_rearEnd()
{
    int item;
    if( isEmpty() )
    {
        printf("Queue Underflow\n");
        exit(1);
    }
    item=s[rear];

    if(front==rear) /*queue has only one element*/
    {
        front=-1;
        rear=-1;
    }
    else if(rear==0)
        rear=MAX-1;
    else
        rear=rear-1;
    return item;
}
int isFull()
{
    if ( (front==0 && rear==MAX-1) || (front==rear+1) )
        return 1;
    else
        return 0;
}
int isEmpty()
{
    if( front == -1)
        return 1;
    else
        return 0;
}
void display()
{
    int i;
    if( isEmpty() )
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements :\n");
    i=front;
    if( front<=rear )
    {
        while(i<=rear)
            printf("%d ",s[i++]);
    }
    else
    {while(i<=MAX-1)
            printf("%d ",s[i++]);
        i=0;
        while(i<=rear)
            printf("%d ",s[i++]);
    }
    printf("\n");
}
