#include <stdio.h>
#include <string.h>
#include <ctype.h>

void findLongestWord(const char *str)
{
    int maxLen=0,currLen=0,i=0,start=0,longStart=0;
    while(str[i]!='\0')
    {
        if(str[i]!=' '){
            if(currLen==0){
                start=i;
            }
                currLen++;
            
        }
        else{
            if(currLen>maxLen)
            {
                maxLen=currLen;
                longStart=start;
            }
            currLen=0;
        }
         i++;
    }
    if(currLen>maxLen)
            {
                maxLen=currLen;
                longStart=start;
            }
    printf("%d",maxLen);
}

int main()
{
    char sentence[100];
    scanf("%[^\n]",sentence);
    findLongestWord(sentence);
    return 0;
}