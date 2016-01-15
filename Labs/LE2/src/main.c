#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int main (void)
{
    char * * theArray;
    int i;
    int num;
    char buffer[50];
    
    printf("How many elements in the array? ");
    scanf("%d", &num);
    getchar();
    theArray = createArray(num);
    for (i=0; i<num; i++)
    {
        printf("enter element %d ", i);
        fgets(buffer, 100, stdin);
        removeNewLine(buffer);
        addElement(theArray, buffer, i);
    }
    
    /*printArray(theArray, num);
    freeArrayElements(theArray, num);*/
    free(theArray);
    return (0);
}