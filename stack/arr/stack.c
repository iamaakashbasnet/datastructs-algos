#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 4

int top = -1, inp_array[SIZE];
bool isOverflow();
bool isUnderflow();
void push();
void pop();
void show();

int main()
{
    int choice;

    while (1)
    {
    menu:
        printf("\nPerform operations on the stack:");
        printf("\n1.Push the element\n2.Pop the element\n3.Show\n4.End");
        printf("\n\nEnter the choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            show();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nInvalid choice!!");
            choice = 0;
            goto menu;
        }
    }

    return 0;
}

bool isOverflow()
{
    if (top == SIZE - 1)
        return true;
    return false;
}

bool isUnderflow()
{
    if (top == -1)
        return true;
    return false;
}

void push()
{
    int x;

    if (isOverflow())
    {
        printf("\nOverflow!!\n");
    }
    else
    {
        printf("\nEnter the element to be added onto the stack: ");
        scanf("%d", &x);
        top = top + 1;
        inp_array[top] = x;
    }
}

void pop()
{
    if (isUnderflow())
    {
        printf("\nUnderflow!!\n");
    }
    else
    {
        printf("\nPopped element: %d\n", inp_array[top]);
        top = top - 1;
    }
}

void show()
{
    if (isUnderflow())
    {
        printf("\nUnderflow!!\n");
    }
    else
    {
        printf("\nElements present in the stack: \n");
        for (int i = top; i >= 0; --i)
        {
            printf("| %d |\n", inp_array[i]);
            if (i == 0)
                printf(" ⎻⎻⎻ ");
        }
    }
}