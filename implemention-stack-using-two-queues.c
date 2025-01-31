#include <stdio.h>
#include <stdlib.h>

typedef struct Queue{
    int size;
    int front;
    int rear;
    int *arr;
} Queue;

Queue *createQueue(int queueSize)
{
   Queue *newQueue=(Queue *)malloc(sizeof(Queue));
   if(newQueue==NULL)
   {
    printf("memory allocation failed!\n");
    exit(1);
   }
   newQueue->size=queueSize;
   newQueue->arr=(int *)malloc(sizeof(int)*queueSize);
   if(newQueue->arr==NULL)
   {
    printf("memory allocation failed!\n");
    exit(1);
   }
   newQueue->front=-1;
   newQueue->rear=-1;
   return newQueue;
}

int isFull(Queue* queue)
{
    if(queue->rear==queue->size-1) return 1;
    return 0;
}

int isEmpty(Queue* queue)
{
    if(queue->front==-1 || queue->front>queue->rear) return 1;
    return 0;
}

void enqueue(Queue* queue,int value)
{
     if(queue->front==-1)
     {
        queue->front++;
     }
     queue->rear++;
     queue->arr[queue->rear]=value;
}

int dequeue(Queue* queue)
{
    int value=queue->arr[queue->front++];
    return value;
}
int size(Queue* queue)
{
    if(isEmpty(queue))
    {
        return 0;
    }
    return (queue->rear-queue->front+1);
}
void peek(Queue* queue)
{
    if(isEmpty(queue))
    {
        printf("Stack is Empty!\n");
        return;
    }
    printf("Top element is %d.\n",queue->arr[queue->front]);
}
void display(Queue* queue)
{
   if(isEmpty(queue))
    {
        printf("Stack is Empty!\n");
        return;
    }
   printf("All the elements are:");
   for(int i=queue->front;i<=queue->rear;i++)
   {
    printf("%d ",queue->arr[i]);
   }
   printf("\n");
}
void freeQueue(Queue* queue)
{
    while(!isEmpty(queue))
    {
        dequeue(queue);
    }
    free(queue);
}

typedef struct Stack{
    Queue* mainQueue;
    Queue* helperQueue;
} Stack;

Stack* createStack(int size)
{
    Stack* st=(Stack *)malloc(sizeof(Stack));
    if(st==NULL)
    {
        printf("Memory can't allocated for stack\n");
        exit(1);
    }
    st->mainQueue=createQueue(size);
    st->helperQueue=createQueue(size);
    return st;
}

void push(Stack* stack,int value)
{
    if(isFull(stack->mainQueue))
    {
        printf("Stack Overflow!\n");
        return;
    }
    enqueue(stack->helperQueue,value);
    while(!isEmpty(stack->mainQueue))
    {
    enqueue(stack->helperQueue,dequeue(stack->mainQueue));
    }
    Queue* temp=stack->mainQueue;
    stack->mainQueue=stack->helperQueue;
    stack->helperQueue=temp;
    stack->helperQueue->front=stack->helperQueue->rear=-1;
    temp=NULL;
    free(temp);
}

int pop(Stack* stack)
{
    if(isEmpty(stack->mainQueue))
    {
        printf("Stack Underflow!\n");
        return -1;
    }
    dequeue(stack->mainQueue);
    while(!isEmpty(stack->mainQueue))
    {
        enqueue(stack->helperQueue,dequeue(stack->mainQueue));
    }
    Queue* temp=stack->mainQueue;
    stack->mainQueue=stack->helperQueue;
    stack->helperQueue=temp;
    stack->helperQueue->front=stack->helperQueue->rear=-1;
    temp=NULL;
    free(temp);
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
            if(isEmpty(stack->mainQueue))
            {
                printf("stack is Empty.\n");
            }
            else{
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
            peek(stack->mainQueue);
        }
        else if(choice==4)
        {
            display(stack->mainQueue);
        }
        else if(choice==5)
        {
            int sizeOfStack=size(stack->mainQueue);
            if(!(sizeOfStack))
            {
                printf("Stack is Empty.\n");
            }
            else{
                printf("Stack size is %d.\n",sizeOfStack);
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
    freeQueue(stack->mainQueue);
    free(stack);

}
int main()
{
    displayMenu();
    return 0;
}

