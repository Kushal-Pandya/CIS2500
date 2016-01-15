#ifndef _PANDYAK__
#define _PANDYAK_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 5

typedef struct Pet 
{
    int speed;
    char * name;
    char * breed;
}Pet;

Pet ** createArray(int size);
Pet * createPet(char * nameBuffer, char * breedBuffer, double animalSpeed);
Pet * findFastest(Pet ** petArray, int size);
Pet * findSlowest(Pet ** petArray, int size);
void printPet(Pet * fastestPet);
void printArray(Pet ** petArray, int size);
void freeArrayElements(Pet ** petArray, int size);
#endif
