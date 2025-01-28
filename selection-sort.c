#include <stdio.h>
#include <stdlib.h>

void takeInput(int *array,int* arrayLength)
{
    while(1){
        scanf("%d",array+(*arrayLength));
        (*arrayLength)++;
        char lastChar=getchar();
        if(lastChar=='\n' || lastChar==EOF) break;
    }
}
void swapNumbers(int *value1, int *value2)
{
    int temp=*value1;
    *value1=*value2;
    *value2=temp;
}
void printArray(int *array,int arraySize)
{
    int index=0;
    while(index<arraySize)
    {
        printf("%d ",*(array+index));
        index++;
    }
}
 void selectionSort(int *array, int arrayLength)
 {
    for(int outerIndex=0;outerIndex<arrayLength-1;outerIndex++)
    {
        int minIndex=outerIndex;

        for(int innerIndex=outerIndex+1;innerIndex<arrayLength;innerIndex++)
        {
            if(*(array+innerIndex) < *(array+minIndex))
            {
                minIndex=innerIndex;
            }
        }
        swapNumbers(array+minIndex,array+outerIndex);
    }
 }

int main()
{
    int arrayLength;
    int *array=(int *)malloc(sizeof(int)*1000);
    takeInput(array,&arrayLength);
    selectionSort(array,arrayLength);
    printArray(array,arrayLength);
    return 0;
}