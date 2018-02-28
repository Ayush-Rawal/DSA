#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<math.h>

typedef struct Stack {
    uint32_t capacity;
    int32_t top;
    int32_t *data;
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

void moveDisk(char fromPeg, char toPeg, int disk)
{
    printf("Move the disk %d from %c to %c\n", disk, fromPeg, toPeg);
    return;
}

void MoveDisksBetweenPoles(Stack *src, Stack *dest, char s, char d)
{
    int pole1TopDisk = Pop(src);
    int pole2TopDisk = Pop(dest);
 
    if (pole1TopDisk == INT32_MIN)
    {
        Push(src, pole2TopDisk);
        moveDisk(d, s, pole2TopDisk);
    }
 
    else if (pole2TopDisk == INT32_MIN)
    {
        Push(dest, pole1TopDisk);
        moveDisk(s, d, pole1TopDisk);
    }

    // When top disk of pole1 > top disk of pole2
    else if (pole1TopDisk > pole2TopDisk)
    {
        Push(src, pole1TopDisk);
        Push(src, pole2TopDisk);
        moveDisk(d, s, pole2TopDisk);
    }
 
    else
    {
        Push(dest, pole2TopDisk);
        Push(dest, pole1TopDisk);
        moveDisk(s, d, pole1TopDisk);
    }
}
 
void ToH(Stack *src, Stack *aux, Stack *dest, uint32_t num_disks)
{
    int32_t i;
    int64_t total_num_of_moves;
    char s = 'S', d = 'D', a = 'A';
 
    // If number of disks is even, then interchange destination pole and auxiliary pole
    if (num_disks % 2 == 0)
    {
        char temp = d;
        d = a;
        a  = temp;
    }
    total_num_of_moves = pow(2, num_disks) - 1;
 
    for (i = num_disks; i >= 1; i--)
        Push(src, i);
 
    for (i = 1; i <= total_num_of_moves; i++)
    {
        if (i % 3 == 1){
            MoveDisksBetweenPoles(src, dest, s, d);
        } 
        else if (i % 3 == 2){
          MoveDisksBetweenPoles(src, aux, s, a);
        } 
        else if (i % 3 == 0){
          MoveDisksBetweenPoles(aux, dest, a, d);
        }
    }
}
 
int main()
{
    uint32_t num_disks;
    printf("Enter number of disks\n");
    scanf("%d", &num_disks);
 
    Stack *src = Initialiaze_Stack(num_disks);
    Stack *aux = Initialiaze_Stack(num_disks);
    Stack *dest = Initialiaze_Stack(num_disks);
 
    ToH(src, aux, dest, num_disks);
    return 0;
}