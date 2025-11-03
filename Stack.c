#include<stdio.h>

#define TOTAL 10

int push(int stack[], int top);
int pop(int stack[], int top);
void peek(int stack[], int top);
void display(int stack[], int top);

int main()
{
    int stack[TOTAL];
    int top = -1;
    int choice, flag = 1;

    while(flag == 1)
    {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push (Insert an element into the stack)\n");
        printf("2. Pop (Remove the top element from the stack)\n");
        printf("3. Peek (Display the top element without removing it)\n");
        printf("4. Display (Show all elements currently in the stack)\n");
        printf("0. Exit (Terminate the program)\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                top = push(stack, top);
                break;
            case 2:
                top = pop(stack, top);
                break;
            case 3:
                peek(stack, top);
                break;
            case 4:
                display(stack, top);
                break;
            case 0:
                printf("Terminating the program!\n");
                flag = 0;
                break;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

int push(int stack[], int top)
{
    int number;
    if (top == TOTAL - 1) {
        printf("Stack Overflow! Cannot push more elements.\n");
    } else {
        printf("Enter number to push: ");
        scanf("%d", &number);
        top++;
        stack[top] = number;
        printf("%d pushed.\n", number);
    }
    return top;
}

int pop(int stack[], int top)
{
    if (top == -1) {
        printf("Stack Underflow.\n");
    } else {
        printf("%d popped.\n", stack[top]);
        top--;
    }
    return top;
}

void peek(int stack[], int top)
{
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Top element is: %d\n", stack[top]);
    }
}

void display(int stack[], int top)
{
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Elements in stack are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}
