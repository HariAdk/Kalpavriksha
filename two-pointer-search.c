#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void inputArray(int array[],int* arrayLength)
{
    while(1){
        scanf("%d",&array[(*arrayLength)]);
        (*arrayLength)++;
        char lastChar=getchar();
        if(lastChar=='\n' || lastChar==EOF) break;
    }
}
void printArray(int array[],int arrayLength)
{
    for(int row=0;row<arrayLength;row++)
    {
       printf("%d ",array[row]);
    }
    printf("\n");
}

bool twoPointerSearch(int *array,int arrayLength,int key)
{
    int start=0;
    int end=arrayLength-1;
    while(start<=end)
    {
        if(array[start++]==key || array[end--]==key)
        {
            return true;
        }
    }
    return false;
}


int main()
{
    int arrayLength=0;
    int key;
    int array[1000];
    inputArray(array,&arrayLength);
    scanf("%d",&key);
    bool isKeyPresent=twoPointerSearch(array,arrayLength,key);
    if(!isKeyPresent)
    {
        printf("Key is not present");
        return 0;
    }
    printf("Key is present");
    return 0;
}