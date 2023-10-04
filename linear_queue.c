// Program to implement LINEAR QUEUE using array
// Name: Agamya Samuel
// Roll No: 22BTCSE042
// Date of Submission: 14/09/23

#include<stdio.h>
#include<stdlib.h>

# define MAX 5
int queue[MAX];
int front=-1;
int rear=-1;
int item;

void insertAll();
void deleteOne();
void display();


void insertAll()
{
    if(rear==MAX-1)
    {
        printf("\nQueue overflow.\n");
        return;
    }
    if(front==-1)
    {
        front=0;
    }
    for(int i = 0; i < MAX; i++)
    {
        printf("\nEnter the element to be inserted: ");
        scanf("%d",&item);
        rear=rear+1;
        queue[rear]=item;
    }
    display();
}

void deleteOne()
{
    if(front==-1||front>rear)
    {
        printf("\nQueue is empty.\n");
        front=-1;
        rear=-1;
        return;
    }
    item=queue[front];
    front=front+1;
    printf("\nDeleted element is %d\n",item);
    display();
}

void display()
{
    int i;
    if(front==-1||front>rear)
    {
        printf("\nQueue is empty\n");
        front=-1;
        rear=-1;
        return;
    }
    printf("\nElements of the queue are:\n");
    for(i=front;i<=rear;i++)
    {
        printf("%d, ",queue[i]);
    }
    printf("\n");
}

int main()
{
    system("cls");  //clears the screen
    int ch;
    while(1)
    {
        printf("**************************************************");
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        printf("**************************************************");
        switch(ch)
        {
            case 1:
            {
                insertAll();
                break;
            }
            case 2:
            {
                deleteOne();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                exit(0);
            }
            default:
            {
                printf("\nInvalid choice\n");
            }
        }
    }
}