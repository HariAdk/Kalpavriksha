#include <stdio.h>
#include <stdlib.h>

typedef struct Stack{
    int size;
    int top;
    int *arr;
} Stack;

Stack *createStack(int stackSize)
{
   Stack *newStack=(Stack *)malloc(sizeof(Stack));
   if(newStack==NULL)
   {
    printf("memory allocation failed!\n");
    exit(1);
   }
   newStack->size=stackSize;
   newStack->arr=(int *)malloc(sizeof(int)*stackSize);
   if(newStack->arr==NULL)
   {
    printf("memory allocation failed!\n");
    exit(1);
   }
   newStack->top=-1;
   return newStack;
}

int isFull(Stack* stack)
{
    if(stack->top==stack->size-1) return 1;
    return 0;
}

int isEmpty(Stack* stack)

{
    if(stack->top==-1) return 1;
    return 0;
}

void push(Stack* stack,int value)
{
     if(isFull(stack))
     {
        printf("Stack Overflow!\n");
        return;
     }
     stack->top++;
     stack->arr[stack->top]=value;
}

void pop(Stack* stack)
{
    if(isEmpty(stack))
    {
        printf("Stack Underflow!\n");
        return;
    }
    stack->top--;
}
int size(Stack* stack)
{
    return stack->top;
}
void peek(Stack* stack)
{
    if(isEmpty(stack))
    {
        printf("Stack is Empty!\n");
        return;
    }
    printf("Top element is %d.\n",stack->arr[stack->top]);
}
void displayStack(Stack* stack)
{
   int stackSize=stack->top;
   if(stackSize==-1)
   {
    printf("Stack is Empty!\n");
    return;
   }
   printf("All the elements are:");
   for(int i=stackSize;i>=0;i--)
   {
    printf("%d ",stack->arr[i]);
   }
   printf("\n");
}
void freeStack(Stack* stack)
{
    while(!isEmpty(stack))
    {
        pop(stack);
    }
    free(stack);
}
void displayMenu()
{
    int stackSize;
    printf("Enter the size of stack:");
    scanf("%d",&stackSize);
    Stack *stack=createStack(stackSize);
    int noOfOperations;
    printf("Enter the number of operations:");
    scanf("%d",&noOfOperations);
    while(noOfOperations--)
    {
        printf("\nEnter 0 to check stack is empty or not-\nEnter 1 for push-\nEnter 2 for pop-\nEnter 3 to peek-\nEnter 4 to display-\nEnter 5 to print size-\nEnter 6 to exit-\n");
        int choice;
        scanf("%d",&choice);
        if(choice==0)
        {
            if(isEmpty(stack))
            {
                printf("Stack is empty.\n");
            }
            else {
                printf("Stack is not empty.\n");
            }
        }
        else if(choice==1)
        {
            printf("Enter a value you want to push:");
            int value;
            scanf("%d",&value);
            push(stack,value);
        }
        else if(choice==2)
        {
            pop(stack);
        }
        else if(choice==3)
        {
            peek(stack);
        }
        else if(choice==4)
        {
            displayStack(stack);
        }
        else if(choice==5)
        {
            int stackSize=size(stack);
            if(!(stackSize+1))
            {
                printf("Stack is Empty.\n");
            }
            else{
                printf("Stack size is %d.\n",stackSize+1);
            }
        }
         else if(choice==6)
        {
            break;
        }
        else{
            printf("Invalid Choice!\n");
        }
    }
    freeStack(stack);

}
int main()
{
    displayMenu();
    return 0;
}