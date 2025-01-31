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
    if(queue->front==-1 || queue->front > queue->rear || queue->front==queue->size) return 1;
    return 0;
}

void enqueue(Queue* queue,int value)
{
     if(isFull(queue))
     {
        printf("Queue Overflow!\n");
        return;
     }
     if(queue->front==-1)
     {
        queue->front++;
     }
     queue->rear++;
     queue->arr[queue->rear]=value;
}

void dequeue(Queue* queue)
{
    if(isEmpty(queue))
    {
        printf("Queue Underflow!\n");
        return;
    }
    queue->front++;
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
        printf("Queue is Empty!\n");
        return;
    }
    printf("Front element is %d.\n",queue->arr[queue->front]);
}
void displayQueue(Queue* queue)
{
   if(isEmpty(queue))
    {
        printf("Queue is Empty!\n");
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
void displayMenu()
{
    int queueSize;
    printf("Enter the size of queue:");
    scanf("%d",&queueSize);
    Queue *queue=createQueue(queueSize);
    int noOfOperations;
    printf("Enter the number of operations:");
    scanf("%d",&noOfOperations);
    while(noOfOperations--)
    {
        printf("\nEnter 0 to check queue is empty or not-\nEnter 1 for enqueue-\nEnter 2 for dequeue-\nEnter 3 to peek-\nEnter 4 to display-\nEnter 5 to print size-\nEnter 6 to exit-\n");
        int choice;
        scanf("%d",&choice);
        if(choice==0)
        {
            if(isEmpty(queue))
            {
                printf("Queue is Empty.\n");
            }
            else{
                printf("Queue is not empty.\n");
            }
        }
        else if(choice==1)
        {
            printf("Enter a value you want to enqueue:");
            int value;
            scanf("%d",&value);
            enqueue(queue,value);
        }
        else if(choice==2)
        {
            dequeue(queue);
        }
        else if(choice==3)
        {
            peek(queue);
        }
        else if(choice==4)
        {
            displayQueue(queue);
        }
        else if(choice==5)
        {
            int sizeOfQueue=size(queue);
            if(!(sizeOfQueue))
            {
                printf("Queue is Empty.\n");
            }
            else{
                printf("Queue size is %d.\n",sizeOfQueue);
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
    freeQueue(queue);

}
int main()
{
    displayMenu();
    return 0;
}