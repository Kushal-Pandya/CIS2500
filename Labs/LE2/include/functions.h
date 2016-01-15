#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * * createArray(int num);
int removeNewLine(char buffer[50]);
void addElement(char * * theArray, char buffer[50], int i);
void printArray(char * * theArray, int num);
void freeArrayElements(char * * theArray, int num);