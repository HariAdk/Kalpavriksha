#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;

Node* createNode(int value)
{
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=value;
    newNode->next=NULL;
    return newNode;
}

void insertNodeAtTail(Node** head,int value)
{
    if((*head)==NULL)
    {
        *head=createNode(value);
        return;
    }
    Node *tail=*head;
    while(tail->next!=NULL)
    {
       tail=tail->next;
    }
    Node* tempNode=createNode(value);
    tail->next=tempNode;
}
void takeInput(Node** head)
{
    int value;
    while(1){
   if(scanf("%d",&value)!=1) break;
   insertNodeAtTail(head,value);
   char lastChar=getchar();
   if(lastChar=='\n' || lastChar==EOF) break;
    }
}

void printList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

Node* split(Node* head)
{
    Node* fastPointer=head;
    Node* slowPointer=head;
    while(fastPointer!=NULL && fastPointer->next!=NULL)
    {
        fastPointer=fastPointer->next->next;
        if(fastPointer!=NULL)
        {
            slowPointer=slowPointer->next;
        }
    }
    fastPointer=slowPointer->next;
    slowPointer->next=NULL;
    return fastPointer;
}

Node* merge(Node* firstNode, Node* secondNode)
{
    if(firstNode==NULL) return secondNode;
    if(secondNode==NULL) return firstNode;

    if(firstNode->data < secondNode->data)
    {
        firstNode->next=merge(firstNode->next,secondNode);
        return firstNode;
    }
    else{
        secondNode->next=merge(firstNode,secondNode->next);
        return secondNode;
    }
}

Node* mergeSort(Node *head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }

    Node* secondNode=split(head);
    head= mergeSort(head);
    secondNode=mergeSort(secondNode);
    return merge(head,secondNode);
}

Node* merge2Lists(Node* head1,Node* head2)
{
    Node* dummy=createNode(0);
    Node* currentNode=dummy;

    while(head1!=NULL && head2!=NULL)
    {
        if(head1->data <= head2->data)
        {
            currentNode->next=head1;
            head1=head1->next;
            currentNode=currentNode->next;
            currentNode->next=NULL;
        }
        else{
            currentNode->next=head2;
            head2=head2->next;
            currentNode=currentNode->next;
            currentNode->next=NULL;
        }
    }

    while(head1!=NULL)
    {
            currentNode->next=head1;
            head1=head1->next;
            currentNode=currentNode->next;
            currentNode->next=NULL;   
    }
    while(head2!=NULL)
    {
            currentNode->next=head2;
            head2=head2->next;
            currentNode=currentNode->next;
            currentNode->next=NULL;
    }
    return dummy->next;
}

Node* removeDuplicateKeys(Node* head,int key)
{
    int count=0;
    Node* currentNode=head;
    Node* previousNode=head;
    while(currentNode!=NULL)
    {
        if(currentNode->data==key)
        {
            count++;
        }
        if(currentNode->data==key && count>1)
        {
            Node* tempNode=currentNode;
            previousNode->next=currentNode->next;
            currentNode=currentNode->next;
            tempNode->next=NULL;
            free(tempNode);
            continue;
        }
        previousNode=currentNode;
        currentNode=currentNode->next;
    }
    return head;
}

int main() {
    Node* head1=NULL;
    Node* head2=NULL;
    takeInput(&head1);
    takeInput(&head2);
    head1=mergeSort(head1);
    head2=mergeSort(head2);
    Node *mergedList = merge2Lists(head1,head2);
    int key;
    scanf("%d",&key);
    mergedList=removeDuplicateKeys(mergedList,key);
    printList(mergedList);  
    return 0;
}
