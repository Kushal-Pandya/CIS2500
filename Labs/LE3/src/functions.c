#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Pet * * createArray(int size)
{   
    Pet ** tempPtr;
    tempPtr = malloc(sizeof(Pet *)* SIZE);
    return tempPtr;
}

Pet * createPet(char * nameBuffer, char * breedBuffer, double animalSpeed)
{
    Pet * tempPtr = malloc(sizeof(Pet));
    tempPtr->name = malloc(sizeof(char) *(strlen(nameBuffer+1)));
    tempPtr->breed = malloc(sizeof(char)*(strlen(breedBuffer+1)));
    tempPtr->speed = animalSpeed;
    strcpy(tempPtr->name, nameBuffer);
    strcpy(tempPtr->breed, breedBuffer);
    //strcpy(tempPtr->speed, &animalSpeed);
    return tempPtr;
}

Pet * findFastest(Pet ** petArray, int size)
{
    return 0;
}

Pet * findSlowest(Pet ** petArray, int size)
{
    return 0;
}

void printPet(Pet * tempPtr)
{
  // printf("%s the %s with speed %d", tempPtr->name, tempPtr->breed, tempPtr->speed); 
}

void printArray(Pet ** petArray, int size)
{
    int i;
    for (i=0; i<SIZE; i++)
    {
        printf("%s the %s with speed %d\n ", petArray[i]->name, petArray[i]->breed, petArray[i]->speed);    
    }
}

void freeArrayElements(Pet ** petArray, int size)
{
    int i;
    for (i=0; i< SIZE; i++)
    {
       free(petArray[i]);
    }
}
