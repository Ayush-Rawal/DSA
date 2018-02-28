#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<math.h>

typedef struct Stack {
    uint32_t capacity;
    int32_t top, *data;
} Stack;

Stack* Initialiaze_Stack(const uint32_t capacity)
{
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->data = (uint32_t*)malloc(capacity * sizeof(uint32_t));
    return stack;
}

uint8_t Is_Full(Stack *stack)
{
    return stack->top == stack->capacity - 1;
}

uint8_t Is_Empty(Stack *stack)
{
    return stack->top == -1;
}

void Push(Stack *stack, int32_t data)
{
    if (Is_Full(stack)) {
        printf("\nCannot push -- Stack is full.\n");
        return;
    }
    stack->data[++(stack->top)] = data;
    return;
}

int32_t Pop(Stack *stack)
{
    if (Is_Empty(stack)) {
        printf("\nCannot pop -- Stack is empty.\n");
        return INT32_MIN;
    }
    return stack->data[stack->top--];
}

void Print_Stack(Stack *stack)
{
    if (Is_Empty(stack)) {
        printf("\nStack is empty\n");
        return;
    }
    uint32_t temp = stack->top;
    while (temp >= 0) {
        printf("%d",stack->data[temp]);
        temp--;
    }
    printf("\n");
}

Stack* Dec2Bin(uint32_t num)
{
    double log_val = log(num)/log(2);
    uint32_t length = ceil(log_val);

    // If log2(num) is integer then add 1 to it.
    if (log_val == ceil(log_val)){
        length++;
    }
    
    Stack *bin = Initialiaze_Stack(length);

    do {
        Push(bin, num % 2);
        num /= 2;
    }while(num);

    return bin;

}

int main(int argc, char *argv[])
{
    // Dec 2 Bin
    uint32_t num;
    printf("Enter number you want to convert to Binary\n");
    scanf("%d",&num);
    printf("\nBinary representation is:\n\n");
    Print_Stack(Dec2Bin(num));
    return 0;
}