// Program in C to implement a stack using linked list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void push(int);
void pop();
void display();

struct node *top = NULL;

void push(int x)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = x;
    new_node->next = top;
    top = new_node;
    display();
}

void pop()
{
    struct node *temp;
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    temp = top;
    top = top->next;
    free(temp);
}

void display()
{
    struct node *temp;
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    temp = top;
    printf("Stack elements are: ");
    while (temp != NULL)
    {
        printf("%d, ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int choice, x;
    while (1)
    {
        printf("**************************************************\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n**************************************************\n");
        switch (choice)
        {
        case 1:
            printf("Enter the element to be pushed: ");
            scanf("%d", &x);
            push(x);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}