#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}


void insertAtBeginning(int value,Node**head) {
    Node* newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
}


void insertAtEnd(int value,Node** head) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}


void insertAtPosition(int position, int value,Node** head) {
    if (position < 1) {
        printf("Invalid position\n");
        return;
    }
    if (position == 1) {
        insertAtBeginning(value,head);
        return;
    }
    Node* newNode = createNode(value);
    Node* temp = *head;
    for (int i = 1; i < position - 1; i++) {
        if (temp == NULL) {
            printf("Invalid position\n");
            free(newNode);
            return;
        }
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid position\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void display(Node **head) {
    Node* temp = *head;
    if (temp == NULL) {
        printf("\n");
        return;
    }
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


void updateAtPosition(int position, int newValue,Node** head) {
    if (position < 1) {
        printf("Invalid position\n");
        return;
    }
    Node* temp = *head;
    for (int i = 1; i < position; i++) {
        if (temp == NULL) {
            printf("Invalid position\n");
            return;
        }
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }
    temp->data = newValue;
}


void deleteAtBeginning(Node** head) {
    if (*head == NULL) {
        printf("Invalid position\n");
        return;
    }
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}


void deleteAtEnd(Node** head) {
    if (*head == NULL) {
        printf("Invalid position\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(head);
        *head = NULL;
        return;
    }
    Node* temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}


void deleteAtPosition(int position,Node** head) {
    if (position < 1 || *head == NULL) {
        printf("Invalid position\n");
        return;
    }
    if (position == 1) {
        deleteAtBeginning(head);
        return;
    }
    Node* temp = *head;
    for (int i = 1; i < position - 1; i++) {
        if (temp == NULL || temp->next == NULL) {
            printf("Invalid position\n");
            return;
        }
        temp = temp->next;
    }
    if (temp->next == NULL) {
        printf("Invalid position\n");
        return;
    }
    Node* toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
}

void menuOperation(int noOfOperation,Node**head)
{
     for (int i = 0; i < noOfOperation; i++) {
        int operation;
        scanf("%d", &operation);
        if (operation == 1) {
            int value;
            scanf("%d", &value);
            if(-1e3>value || value>1e3)
            {
                printf("Error! Value must be between -10^3 to 10^3\n");
                continue;
            }
            insertAtEnd(value,head);
        } else if (operation == 2) {
            int value;
            scanf("%d", &value);
             if(-1e3>value || value>1e3)
            {
                printf("Error! Value must be between -10^3 to 10^3\n");
                continue;
            }
            insertAtBeginning(value,head);
        
        } else if (operation == 3) {
            int pos, value;
            scanf("%d %d", &pos, &value);
             if(-1e3>value || value>1e3)
            {
                printf("Error! Value must be between -10^3 to 10^3\n");
                continue;
            }
            insertAtPosition(pos, value,head);
        } else if (operation == 4) {
            display(head);
        
        } else if (operation == 5) {
            int pos, value;
            scanf("%d %d", &pos, &value);
            if(-1e3>value || value>1e3)
            {
                printf("Error! Value must be between -10^3 to 10^3\n");
                continue;
            }
            updateAtPosition(pos, value,head);
        } else if (operation == 6) {
            deleteAtBeginning(head);
        } else if (operation == 7) {
            deleteAtEnd(head);
        } else if (operation == 8) {
            int pos;
            scanf("%d", &pos);
            deleteAtPosition(pos,head);
        }
    }

}

int main() {
    int noOfOperations;
    scanf("%d", &noOfOperations);
    if(noOfOperations<1 || noOfOperations>100)
    {
        printf("Error! Operations must be 0<operation<101\n");
        return 0;
    }
    Node* head = NULL;
    menuOperation(noOfOperations,&head);
    return 0;
}
