// Program to implement a linked list
// Created by: Agamya Samuel

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert(int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    printf("Address of new node: %p\n", new_node);

    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = new_node;
    }
}

void delete(int data)
{
    struct node *temp = head;
    struct node *prev = NULL;

    while (temp != NULL)
    {
        if (temp->data == data)
        {
            if (prev == NULL)
            {
                head = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }

            free(temp);
            return;
        }

        prev = temp;
        temp = temp->next;
    }
}

void search(int data)
{
    struct node *temp = head;

    while (temp != NULL)
    {
        if (temp->data == data)
        {
            printf("Found %d\n", data);
            return;
        }

        temp = temp->next;
    }

    printf("Not found\n");
}

void display()
{
    struct node *temp = head;
    printf("\nElements are: \n");
    while (temp != NULL)
    {
        printf("%d, ", temp->data);
        temp = temp->next;
    }
    temp = head;
    printf("\nAddress of the Elements are: \n");
    while (temp != NULL)
    {
        printf("%x, ", temp);
        temp = temp->next;
    }

    printf("\n");
}

int main()
{
    system("cls"); // clears the screen
    int ch;
    while (1)
    {
        printf("**************************************************");
        printf("\n1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        printf("**************************************************");
        switch (ch)
        {
        case 1:
        {
            int no_of_item;
            printf("\nEnter the number of elements to be inserted: ");
            scanf("%d", &no_of_item);
            for (int i = 0; i < no_of_item; i++)
            {
                printf("\nEnter the element: ");
                int item;
                scanf("%d", &item);
                insert(item);
            }
            break;
        }
        case 2:
        {
            printf("\nEnter the item to be deleted: ");
            int item;
            scanf("%d", &item);
            delete (item);
            break;
        }
        case 3:
        {
            printf("\nEnter the item to be searched: ");
            int item;
            scanf("%d", &item);
            search(item);
            break;
        }
        case 4:
        {
            display();
            break;
        }
        case 5:
        {
            exit(0);
        }
        default:
        {
            printf("\nInvalid choice\n");
        }
        }
    }

    return 0;
}