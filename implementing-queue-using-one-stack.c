#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct{
    int arr[MAX];
    int top;
}Stack;
void initStack(Stack *s){
    s->top = -1;
}int isEmptyStack(Stack *s){
    return s->top == -1;
}
void push(Stack *s, int value){
    if(s->top == MAX-1){
        printf("Stack is full\n");
        return;
    }
    s->arr[++s->top] = value;
}
int pop(Stack *s){
    if(isEmptyStack(s)){
       printf("Queue is empty\n");
       return -1;
    }
    int val = s->arr[s->top];
    s->top--;
    return val;
}
typedef struct{
    Stack s;
}Queue;
void initQueue(Queue* q){
    initStack(&q->s);
}
void insertAtBottom(Stack *s, int value){
    if(isEmptyStack(s)){
        push(s, value);
        return;
    }
    int temp = pop(s);
    insertAtBottom(s, value);
    push(s, temp);
}
void enqueue(Queue* q, int val){
    insertAtBottom(&q->s, val);
}
int dequeue(Queue* q){
    if(isEmptyStack(&q->s)){
        printf("Queue is empty");
        return -1;
    }
    return pop(&q->s);
}
int front(Queue* q){
    if(isEmptyStack(&q->s)){
    printf("Queue is empty\n");
    return -1;
    }
    return q->s.arr[q->s.top];
}
int isEmpty(Queue *q){
    return isEmptyStack(&q->s);
}
int sizeofqueue(Queue* q){
    return q->s.top + 1;
}
int main(){
    Queue queue;
    initQueue(&queue);
    int number_of_operation;
    printf("Enter the number of operation\n");
    scanf("%d", &number_of_operation);
    int choice;
    do{
        printf("MENU\n");
        printf("1. Add an element to the queue\n");
        printf("2. Remove the front element from the queue.\n");
        printf("3. Retrive the front element without removing it\n");
        printf("4. Check if the queue is Empty\n");
        printf("5. Return the number of element in the queue\n");
        printf("6 for exit.\n");
        printf("Enter the choice\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
            printf("Enter the value\n");
            int value1;
            scanf("%d", &value1);
            enqueue(&queue, value1);
            break;
            case 2:{
            int value2 = dequeue(&queue);
            if(value2 != -1)
            printf("%d", value2);
            break;
            }
            case 3:{
            int peekvalue = front(&queue);
            if(peekvalue != -1)
            printf("%d", peekvalue);
            break;
            }
            case 4:{
            int value4 = isEmpty(&queue);
            if(value4){
                printf("The queue is empty\n");
            }else{
                printf("The queue is not empty\n");
            }
            break;
            }
            case 5:
            printf("The size of queue\n");
            int size = sizeofqueue(&queue);
            printf("%d", size);
            break;
            case 6:
            exit(1);
            default:
            printf("Invalid choice\n");
            break;
}
        number_of_operation--;
    }while(number_of_operation > 0);
    return 0;
}