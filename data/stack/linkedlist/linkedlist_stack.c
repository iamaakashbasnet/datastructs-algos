/**
 * @brief Stack using linked list (LIFO)
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *head = NULL;

void push(int data);
void pop();
void display();
void peek();

int main()
{
    push(1);
    push(2);
    push(3);
    display();
    peek();
    pop();
    display();
    peek();
    return 0;
}

void push(int data)
{
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Stack overflow.\n");
        return;
    }

    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void pop()
{
    if (head != NULL)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
    }
    else
    {
        printf("Stack is empty.\n");
    }
}

void display()
{
    if (head == NULL)
    {
        printf("Stack is empty.\n");
        return;
    }

    Node *curr = head;
    printf("Stack contents: ");
    while (curr != NULL)
    {
        printf("%d <- ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

void peek()
{
    if (head != NULL)
    {
        printf("Head currently points to %d.\n", head->data);
    }
}