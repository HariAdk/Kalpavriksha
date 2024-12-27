#include <stdio.h>
void upSidePattern(int number)
{
     int row,column;
     for (row = 1; row <= number; row++) {
        for (column = 1; column <= row; column++) {
            printf("%d", column);
        }
        for (column = 1; column <= (2 * (number - row)); column++) {
            printf(" ");
        }
        for (column = row; column >= 1; column--) {
            printf("%d", column);
        }
        printf("\n");
    }
}

void downSidePattern(int number)
{
   int row,column;
   for (row = number - 1; row >= 1; row--) {
        for (column = 1; column <= row; column++) {
            printf("%d", column);
        }
        for (column = 1; column <= (2 * (number - row)); column++) {
            printf(" ");
        }
        for (column = row; column >= 1; column--) {
            printf("%d", column);
        }
        printf("\n");
    }
}

int main() {
    int number;
    printf("This code prints number in a pattern till nth number\n");
    printf("Enter nth number:");
    scanf("%d", &number);
    printf("\n");
    upSidePattern(number);
    downSidePattern(number); 
    return 0;
}
