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
void clrscr();

int main()
{
    int choice;
    int data;

    while (1)
    {
        display();

        printf("\nPerform operations on the linked list stack:\n");
        printf("1. Push the element\n2. Pop the element\n3. Peek\n4. End\n");
        printf("\nEnter the choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data you want to enter: ");
            scanf("%d", &data);
            push(data);
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            // Free allocated memory before exiting
            while (head != NULL)
            {
                pop();
            }
            exit(0);
        default:
            printf("Invalid choice!!\n");
        }
    }
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

    clrscr();
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

    clrscr();
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

// Platform-independent clrscr
void clrscr()
{
    printf("\033[H\033[J");
}
