#include "functions.h"

char * * createArray(int num)
{
    char * * theArray = malloc(sizeof(char *)*num+1);
    return *theArray[num];
}

int removeNewLine(char buffer[50])
{
    buffer = malloc(sizeof(char));
    if (buffer == '\0')
    {
        strlen(buffer+1);
    }
    return 0;
}

void addElement(char * * theArray, char buffer[50], int i)
{
    theArray = malloc(sizeof(char));
    buffer = malloc(sizeof(char));
    
    for(i=0; i<buffer; i++)
    {
        theArray[i] = strcpy(theArray, buffer);
    }
}

void printArray(char * * theArray, int num)
{
    int i;
    for (i=0; i<num; i++)
    {
        printf("%s", strcpy(theArray, buffer);
    }

}

void freeArrayElements(char * * theArray, int num)
{
    int i;
    for (i=0; i<num; i++)
    {
        free(theArray[i]);
    }
}
