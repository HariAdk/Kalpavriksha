#include <stdio.h>
#include <stdlib.h>

void swapNumbers(int *value1, int *value2)
{
    int temp=*value1;
    *value1=*value2;
    *value2=temp;
}
void takeInput(int *array,int* arrayLength)
{
    while(1){
        scanf("%d",array+(*arrayLength));
        (*arrayLength)++;
        char lastChar=getchar();
        if(lastChar=='\n' || lastChar==EOF) break;
    }
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

int partition(int *array,int start,int end)
{
    int maxValue=*(array+end);
    int pivotIndex=start; 

    for (int i=start;i<end;i++)
    {
        if (*(array+i)<=maxValue)
        {
            swapNumbers(array+pivotIndex,array+i);
            pivotIndex++;
        }
    }
    swapNumbers(array+pivotIndex, array+end);

    return pivotIndex;
}

void quickSort(int *array,int start,int end)
{
    if (start<end)
    {
        int pivotIndex = partition(array,start,end);
        quickSort(array,start,pivotIndex-1);
        quickSort(array,pivotIndex+1,end);
    }
}

int main()
{
    int arrayLength;
    int *array=(int *)malloc(sizeof(int)*1000);
    takeInput(array,&arrayLength);
    quickSort(array,0,arrayLength-1);
    printArray(array,arrayLength);
    return 0;
}