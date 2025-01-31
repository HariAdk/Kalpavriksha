#include <stdio.h>
#include <stdlib.h>


typedef struct Stack {
    int* arr;
    int top;
    int size;
} Stack;

Stack* createStack(int size) {
    Stack* newStack = (Stack*)malloc(sizeof(Stack));
    newStack->arr = (int*)malloc(sizeof(int) * size);
    newStack->size = size;
    newStack->top = -1;
    return newStack;
}

int isFull(Stack* stack) {
    return stack->top == stack->size - 1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->arr[++stack->top] = value;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

int peek(Stack* stack) {
    if (isEmpty(stack)) {
        return -1;
    }
    return stack->arr[stack->top];
}

void freeStack(Stack* stack) {
    free(stack->arr);
    free(stack);
}

typedef struct QueueUsingTwoStacks {
    Stack* stack1;  
    Stack* stack2;  
} QueueUsingTwoStacks;

QueueUsingTwoStacks* createQueue(int size) {
    QueueUsingTwoStacks* queue = (QueueUsingTwoStacks*)malloc(sizeof(QueueUsingTwoStacks));
    queue->stack1 = createStack(size);
    queue->stack2 = createStack(size);
    return queue;
}


int isQueueEmpty(QueueUsingTwoStacks* queue) {
    return isEmpty(queue->stack1) && isEmpty(queue->stack2);
}

void enqueue(QueueUsingTwoStacks* queue, int value) {
    push(queue->stack1, value);
}

int dequeue(QueueUsingTwoStacks* queue) {
    if (isEmpty(queue->stack2)) {
        while (!isEmpty(queue->stack1)) {
            push(queue->stack2, pop(queue->stack1));
        }
    }
    
    if (isEmpty(queue->stack2)) {
        printf("Queue is Empty\n");
        return -1;
    }
    return pop(queue->stack2);
}

int peekQueue(QueueUsingTwoStacks* queue) {
    if (isEmpty(queue->stack2)) {
       
        while (!isEmpty(queue->stack1)) {
            push(queue->stack2, pop(queue->stack1));
        }
    }
    
    if (isEmpty(queue->stack2)) {
        printf("Queue is Empty\n");
        return -1;
    }
    return peek(queue->stack2);
}


void freeQueue(QueueUsingTwoStacks* queue) {
    freeStack(queue->stack1);
    freeStack(queue->stack2);
    free(queue);
}

void displayMenu() {
    int queueSize;
    printf("Enter the size of queue: ");
    scanf("%d", &queueSize);
    QueueUsingTwoStacks* queue = createQueue(queueSize);
    
    int numOperations;
    printf("Enter the number of operations: ");
    scanf("%d", &numOperations);
    
    while (numOperations--) {
        printf("\nEnter 0 to check queue is empty or not-\nEnter 1 for enqueue-\nEnter 2 for dequeue-\nEnter 3 to peek-\nEnter 4 to display queue-\nEnter 5 to exit-\n");
        int choice;
        scanf("%d", &choice);
        
        if (choice == 0) {
            if (isQueueEmpty(queue)) {
                printf("Queue is Empty.\n");
            } else {
                printf("Queue is not empty.\n");
            }
        } else if (choice == 1) {
            printf("Enter a value you want to enqueue: ");
            int value;
            scanf("%d", &value);
            if(queueSize-->0)
            {
            enqueue(queue, value);
            }
            else{
                printf("Queue Overflow!\n");
            }
            
        } else if (choice == 2) {
            int value = dequeue(queue);
            if (value != -1) {
                printf("Dequeued value: %d\n", value);
            }
        } else if (choice == 3) {
            int value = peekQueue(queue);
            if (value != -1) {
                printf("Front element is: %d\n", value);
            }
        } else if (choice == 4) {
            printf("Queue elements are:\n");
            while (!isQueueEmpty(queue)) {
                printf("%d ", dequeue(queue));
            }
            printf("\n");
        } 
        else if (choice == 5) {
            break;
        } else {
            printf("Invalid Choice!\n");
        }
    }
    
    freeQueue(queue);
}

int main() {
    displayMenu();
    return 0;
}
