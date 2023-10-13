// Program to implement a linked list
// Created by: Agamya Samuel

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert(int data) {
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        struct node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = new_node;
    }
}

void delete(int data) {
    struct node *temp = head;
    struct node *prev = NULL;

    while (temp != NULL) {
        if (temp->data == data) {
            if (prev == NULL) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }

            free(temp);
            return;
        }

        prev = temp;
        temp = temp->next;
    }
}

void print() {
    struct node *temp = head;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main() {
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);

    print();

    delete(3);

    print();

    delete(1);

    print();

    delete(5);

    print();

    return 0;
}