#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <limits.h> 

#define MAX_SIZE 100

//Defining stack for operands
struct StackInt {

    int data[MAX_SIZE];
    int top;

};

//Defining stack for operators
struct StackChar {

    char data[MAX_SIZE];
    int top;

};

// Initializing
void initIntStack(struct StackInt *stack) {

    stack->top = -1;

}

//Initializing
void initCharStack(struct StackChar *stack) {

    stack->top = -1;

}

// Check if the integer stack is empty
int isEmptyIntStack(struct StackInt *stack) {

    return stack->top == -1;

}

// Check if the character stack is empty
int isEmptyCharStack(struct StackChar *stack) {

    return stack->top == -1;

}

// Push integer in the integer stack
void pushInt(struct StackInt *stack, int value) {

    if (stack->top == MAX_SIZE - 1) {

        printf("Error: Stack overflow\n");
        exit(1);

    }
    stack->data[++stack->top] = value;
}

// Push a character in the character stack
void pushChar(struct StackChar *stack, char value) { 

    if (stack->top == MAX_SIZE - 1) {
        printf("Error: Stack overflow\n");
        exit(1);
    }

    stack->data[++stack->top] = value;
}

// Pop integer from the integer stack
int popInt(struct StackInt *stack) {

    if (isEmptyIntStack(stack)) {
        printf("Error: Stack is underflow\n");
        exit(1);
    }

    return stack->data[stack->top--];
}

// Pop character from the character stack
char popChar(struct StackChar *stack) {

    if (isEmptyCharStack(stack)) {
        printf("Error: Stack is underflow\n");
        exit(1);
    }

    return stack->data[stack->top--];
}

// Precedence of an operator
int precedence(char op) {

    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;

}

// Applying an operation on operand
int applyOperation(int a, int b, char op) {

    switch (op) {

        case '+': return a + b;

        case '-': return a - b;

        case '*': return a * b;

        case '/':

            if (b == 0) {

                printf("0 cannot be a divisor.\n");
                exit(1);

            }
            return a / b;
        default:
            printf("Invalid operator.\n");
            exit(1);
    }
}

// Evaluate the expression
int solveExpression(char *expression) {
    struct StackInt values;
    struct StackChar operators;

    initIntStack(&values);
    initCharStack(&operators);

    for (int i = 0; i < strlen(expression); i++) {

        if (isspace(expression[i])) {
            continue;    //if any whitespace
        }

        if (isdigit(expression[i])) {

            int value = 0;
            while (i < strlen(expression) && (isdigit(expression[i]) || isspace(expression[i]))) {

               if (isspace(expression[i])) {
                
                     i++;
                     continue;    
        }
                value = value * 10 + (expression[i] - '0');
                i++;
            }

            i--; 
            pushInt(&values, value);

        } 
        else if (expression[i] == '+' || expression[i] == '-' ||
                   expression[i] == '*' || expression[i] == '/') {

            while (!isEmptyCharStack(&operators) && 
                     precedence(operators.data[operators.top]) >= precedence(expression[i])) {
                   
                int b = popInt(&values);
                int a = popInt(&values);
                char op = popChar(&operators);
                pushInt(&values, applyOperation(a, b, op));

            }

            pushChar(&operators, expression[i]);

        } else {

            printf("Invalid expression.\n");
            return INT_MIN; 

        }
    }

    while (!isEmptyCharStack(&operators)) {
        
        int b = popInt(&values);
        int a = popInt(&values);
        char op = popChar(&operators);
        pushInt(&values, applyOperation(a, b, op));
    }

    return popInt(&values);
}

int main() {
    char expression[MAX_SIZE];

    printf("Enter the values: ");
    fgets(expression, MAX_SIZE, stdin);

    int ans = solveExpression(expression);
    expression[strcspn(expression, "\n")] = '\0';

    if (ans != INT_MIN) {    //if error INT_MIN will be returned
        printf("Result: %d\n", ans);
    }

    return 0;
}


