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
typedef struct Stack{
    int size;
    Node* top;
} Stack;

Stack *createStack()
{
   Stack *newStack=(Stack *)malloc(sizeof(Stack));
   if(newStack==NULL)
   {
    printf("memory allocation failed!\n");
    exit(1);
   }
   newStack->top=NULL;
   newStack->size=0;
   return newStack;
}

int isEmpty(Stack* stack)
{
    if(stack->size==0) return 1;
    return 0;
}

int size(Stack* stack)
{
    return stack->size;
}

void insertAtHead(Stack* stack,int value)
{
    if(stack->size==0)
    {
        stack->top=createNode(value);
        return;
    }
    Node* newNode=createNode(value);
    newNode->next=stack->top;
    stack->top=newNode;
}

void deleteAtHead(Stack* stack)
{
    Node* tempNode=stack->top;
    stack->top=stack->top->next;
    tempNode->next=NULL;
    free(tempNode);
}

void push(Stack* stack,int value)
{ 
    insertAtHead(stack,value);
    stack->size++;
}

void pop(Stack* stack)
{
    if(isEmpty(stack))
    {
        printf("Stack Underflow!\n");
        return;
    }
    deleteAtHead(stack);
    stack->size--;
}
void peek(Stack* stack)
{
    if(isEmpty(stack))
    {
        printf("Stack is Empty!\n");
        return;
    }
    printf("Top value is:");
    printf("%d\n",stack->top->data);
}
void displayStack(Stack* stack)
{
   if(isEmpty(stack))
   {
    printf("Stack is Empty!\n");
    return;
   }
   Node* currentNode=stack->top;
   printf("All values in stack are:");
   while(currentNode!=NULL)
   {
    printf("%d ",currentNode->data);
    currentNode=currentNode->next;
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
    Stack *stack=createStack();
    printf("No of Operations you want to perform:");
    int noOfOperations;
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
            if(!stackSize)
            {
                printf("Stack is Empty.\n");
            }
            else{
                printf("Stack size is %d.\n",stackSize);
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