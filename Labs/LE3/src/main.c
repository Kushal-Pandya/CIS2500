#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

#define SIZE 5

int main (int argc, char * argv[])
{
    FILE * filePtr;
    struct Pet * * petArray;
    struct Pet * fastestPet;
    struct Pet * slowestPet;
    int i;
    char nameBuffer[20];
    char breedBuffer[10];
    double animalSpeed;
    char junk[50];
    
    if (argc != 2) 
    {
        printf("not enough parameters\n"); 
        exit(0);
    }
    filePtr = fopen(argv[1], "r");
    petArray = createArray(SIZE);
    for (i=0;i<SIZE; i++)
    {
        fscanf(filePtr,"%s%s%lf", nameBuffer, breedBuffer, &animalSpeed);
        petArray[i] = createPet(nameBuffer, breedBuffer, animalSpeed);
        fgets(junk, 50, filePtr); //to get rid of new line
    }
    fastestPet = findFastest(petArray, SIZE);
    slowestPet = findSlowest(petArray, SIZE);
    printf("The fast pet is: ");
    printPet(fastestPet);
    printf("\n");
    printf("The slow pet is: ");
    printPet(slowestPet);
    printf("\n");
    printf("Here is the whole array: \n");
    printArray(petArray, SIZE);
    printf("\n");
    freeArrayElements(petArray, SIZE);
    return 0;
}
