#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
}Node;

Node *createNode(int value)
{
    Node* newNode=(Node*)malloc(sizeof(Node));
    if(newNode==NULL)
    {
        free(newNode);
        return NULL;
    }
    newNode->data=value;
    newNode->next=NULL;
    return newNode;
}
typedef struct Queue{
    int size;
    Node* rear;
    Node* front;
} Queue;

Queue *createQueue()
{
   Queue *newQueue=(Queue *)malloc(sizeof(Queue));
   if(newQueue==NULL)
   {
    printf("memory allocation failed!\n");
    exit(1);
   }
   newQueue->rear=NULL;
   newQueue->front=NULL;
   newQueue->size=0;
   return newQueue;
}

int isEmpty(Queue* queue)
{
    if(queue->size==0) return 1;
    return 0;
}

int size(Queue* queue)
{
    return queue->size;
}

void insertAtTail(Queue* queue,int value)
{
    if(queue->size==0)
    {
        queue->rear=createNode(value);
        queue->front=queue->rear;
        return;
    }
    Node* newNode=createNode(value);
    queue->rear->next=newNode;
    queue->rear=newNode;
}

void deleteAtHead(Queue* queue)
{
    Node* tempNode=queue->front;
    queue->front=queue->front->next;
    tempNode->next=NULL;
    free(tempNode);
}

void enqueue(Queue* queue,int value)
{ 
    insertAtTail(queue,value);
    queue->size++;
}

void dequeue(Queue* queue)
{
    if(isEmpty(queue))
    {
        printf("Queue Underflow!\n");
        return;
    }
    deleteAtHead(queue);
    queue->size--;
}
void peek(Queue* queue)
{
    if(isEmpty(queue))
    {
        printf("Queue is Empty!\n");
        return;
    }
    printf("Front value is:");
    printf("%d\n",queue->front->data);
}
void displayQueue(Queue* queue)
{
   if(isEmpty(queue))
   {
    printf("Queue is Empty!\n");
    return;
   }
   Node* currentNode=queue->front;
   printf("All values in queue are:");
   while(currentNode!=NULL)
   {
    printf("%d ",currentNode->data);
    currentNode=currentNode->next;
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
    Queue *queue=createQueue();
    printf("No of Operations you want to perform:");
    int noOfOperations;
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
            if(!sizeOfQueue)
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