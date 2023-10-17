/**
 * @brief Queue using array (FIFO)
 *
 */

#include <stdio.h>

#define SIZE 5

void enqueue(int);
void dequeue();
void display();

int queue[SIZE], front = -1, rear = -1;

int main()
{
    display();
    enqueue(1);
    enqueue(2);
    display();
    dequeue();
    display();

    return 0;
}

void enqueue(int data)
{
    if (rear == SIZE - 1)
    {
        printf("\nQueue is full.\n");
    }
    else
    {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = data;
    }
}

void dequeue()
{
    if (front == -1)
    {
        printf("\nQueue is empty.\n");
    }
    else
    {
        front++;
        if (front > rear)
            front = rear = -1;
    }
}

void display()
{
    if (rear == -1)
        printf("\nQueue is empty.\n");
    else
    {
        printf("\nQueue elements are: ");
        for (int i = front; i <= rear; i++)
        {
            printf("|%d|", queue[i]);
        }
    }
}