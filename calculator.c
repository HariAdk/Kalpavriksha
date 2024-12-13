#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <limits.h> 




struct StInt {

    int val[100];
    int top;

};


struct StChar {

    char val[100];
    int top;

};


void initalizeIntSt(struct StInt *stack) {

    stack->top = -1;

}


void initalizeCharSt(struct StChar *stack) {

    stack->top = -1;

}


int isEmptyIntSt(struct StInt *stack) {

    return stack->top == -1;

}


int isEmptyCharSt(struct StChar *stack) {

    return stack->top == -1;

}


void pushVal(struct StInt *stack, int value) {

    if (stack->top == 99) {

        printf("Error: Stack overflow\n");
        exit(1);

    }
    stack->val[++stack->top] = value;
}


void pushChar(struct StChar *stack, char value) { 

    if (stack->top == 99) {
        printf("Error: Stack overflow\n");
        exit(1);
    }

    stack->val[++stack->top] = value;
}


int popVal(struct StInt *stack) {

    if (isEmptyIntSt(stack)) {
        printf("Error: Stack is underflow\n");
        exit(1);
    }

    return stack->val[stack->top--];
}


char popChar(struct StChar *stack) {

    if (isEmptyCharSt(stack)) {
        printf("Error: Stack is underflow\n");
        exit(1);
    }

    return stack->val[stack->top--];
}


int precedence(char op) {

    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;

}


int Calculate(int a, int b, char op) {

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
            printf("Operator is invalid.\n");
            exit(1);
    }
}


int solveMathExp(char *str) {
    struct StInt value;
    struct StChar operator;

    initalizeIntSt(&value);
    initalizeCharSt(&operator);

    for (int i = 0; i < strlen(str); i++) {

        if (isspace(str[i])) {
            continue;    
        }

        if (isdigit(str[i])) {

            int values = 0;
            while (i < strlen(str) && (isdigit(str[i]) || isspace(str[i]))) {

               if (isspace(str[i])) {
                
                     i++;
                     continue;    
        }
                values = values * 10 + (str[i] - '0');
                i++;
            }

            i--; 
            pushVal(&value, values);

        } 
        else if (str[i] == '+' || str[i] == '-' ||
                   str[i] == '*' || str[i] == '/') {

            while (!isEmptyCharSt(&operator) && 
                     precedence(operator.val[operator.top]) >= precedence(str[i])) {
                   
                int b = popVal(&value);
                int a = popVal(&value);
                char op = popChar(&operator);
                pushVal(&value, Calculate(a, b, op));

            }

            pushChar(&operator, str[i]);

        } else {

            printf("Expression is invalid.\n");
            return INT_MIN; 

        }
    }

    while (!isEmptyCharSt(&operator)) {
        
        int b = popVal(&value);
        int a = popVal(&value);
        char op = popChar(&operator);
        pushVal(&value, Calculate(a, b, op));
    }

    return popVal(&value);
}

int main() {
    char exp[100];

    printf("Enter the expression : ");
    fgets(exp, 100, stdin);

    int result = solveMathExp(exp);
    

    if (result!= INT_MIN) {    
        printf(" Result is:%d\n", result);
    }

    return 0;
}


