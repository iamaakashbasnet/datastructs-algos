/**
 * @brief Stack using array (LIFO)
 *
 */

#include <stdio.h>
#include <stdbool.h>

#define SIZE 4

int top = -1, inp_array[SIZE];
bool isOverflow();
bool isUnderflow();
void push(int);
void pop();
void show();

int main()
{
    push(1);
    show();
    push(2);
    show();
    push(3);
    show();
    pop();
    show();
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

void push(int data)
{
    if (isOverflow())
    {
        printf("\nOverflow!!\n");
    }
    else
    {
        top = top + 1;
        inp_array[top] = data;
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