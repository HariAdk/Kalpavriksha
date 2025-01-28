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
void printArray(int *array,int arraySize)
{
    int index=0;
    while(index<arraySize)
    {
        printf("%d ",*(array+index));
        index++;
    }
}

void insertionSort(int* array, int arrayLength)
{
    for(int i=1;i<arrayLength;i++)
    {
        int key=*(array+i);
        int j=i-1;
        
        while(j>=0 && *(array+j)>key)
        {
            *(array+j+1)=*(array+j);
            j--;
        }
        *(array+j+1)=key;
    }
}

int main()
{
    int arrayLength;
    int *array=(int *)malloc(sizeof(int)*1000);
    takeInput(array,&arrayLength);
    insertionSort(array,arrayLength);
    printArray(array,arrayLength);
    return 0;
}