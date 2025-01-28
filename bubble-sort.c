#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
void takeInput(int *array,int *arrayLength)
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

void bubbleSort(int *array,int arrayLength)
{
    for(int firstIndex=0;firstIndex<arrayLength-1;firstIndex++)
    {
        bool isSwap=false;
       for(int secondIndex=0;secondIndex<arrayLength-firstIndex-1;secondIndex++)
       {
        if(*(array+secondIndex)>*(array+secondIndex+1))
        {
            isSwap=true;
            swapNumbers((array+secondIndex),(array+secondIndex+1));
        }
       }
       if(!isSwap)
       {
        return;
       }
    }
}
int main()
{
    int arrayLength;
    int *array=(int *)malloc(arrayLength*sizeof(int));
    takeInput(array,&arrayLength);
    bubbleSort(array,arrayLength);
    printArray(array,arrayLength);
    return 0;
}