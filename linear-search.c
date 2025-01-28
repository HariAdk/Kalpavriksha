#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void inputArray(int *array,int* arrayLength)
{
    while(1){
        scanf("%d",&array[(*arrayLength)]);
        (*arrayLength)++;
        char lastChar=getchar();
        if(lastChar=='\n' || lastChar==EOF) break;
    }
}
void printArray(int *array,int arrayLength)
{
    for(int row=0;row<arrayLength;row++)
    {
       printf("%d ",array[row]);
    }
    printf("\n");
}

bool linearSearch(int *array,int arrayLength,int key)
{
    for(int index=0;index<arrayLength;index++)
    {
        if(array[index]==key)
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
    int *array=(int*)malloc(sizeof(int)*1000);
    inputArray(array,&arrayLength);
    scanf("%d",&key);
    bool isKeyPresent=linearSearch(array,arrayLength,key);
    if(!isKeyPresent)
    {
        printf("Key is not present");
        return 0;
    }
    printf("Key is present");
    return 0;
}