#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_ROWS 10
#define MAX_COLS 101
#define MAX_NAME_LENGTH 50


int isVowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}


void getDimensions(int *rows, int *cols) {
    do {
        printf("Enter number of rows:");
        scanf("%d", rows);
    } while (*rows < 1 || *rows > MAX_ROWS);

    do {
        printf("Enter number of columns:");
        scanf("%d", cols);
    } while (*cols < 1 || *cols > MAX_COLS);
}


void inputNames(char names[MAX_ROWS][MAX_COLS][MAX_NAME_LENGTH], int rows, int cols) {
    printf("Enter the names:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Name at (%d,%d): ", i, j);
            scanf("%s", names[i][j]);
        }
    }
}


void printNames(char names[MAX_ROWS][MAX_COLS][MAX_NAME_LENGTH], int rows, int cols) {
    printf("\nThe 2D array of names is:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%s\t", names[i][j]);
        }
        printf("\n");
    }
}


void findLongestName(char names[MAX_ROWS][MAX_COLS][MAX_NAME_LENGTH], int rows, int cols) {
    int vowelCount = 0;
    char longestName[MAX_NAME_LENGTH]="";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (isVowel(names[i][j][0])) {
                (vowelCount)++;
            }
            if (strlen(names[i][j]) > strlen(longestName)) {
                strcpy(longestName, names[i][j]);
            }
        }
    }
    printf("\nNumber of names starting with a vowel:%d\n", vowelCount);
    printf("The longest name:%s\n", longestName);
}


int main() {
    int rows, cols;
    char names[MAX_ROWS][MAX_COLS][MAX_NAME_LENGTH];

    getDimensions(&rows, &cols);

    inputNames(names, rows, cols);

    printNames(names, rows, cols);

    findLongestName(names, rows, cols);

    return 0;
}
