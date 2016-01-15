/*************************A2.c*******************************************
2 Student Name: Kushal Pandya                        Student Number: 0888884
3 Due Date: March 13 2015                            Course Name: cis2500
4 I have exclusive control over this submission via my password.
5 By including this statement in this header comment, I certify that:
6     1) I have read and understood the University policy on academic integrity;
7     2) I have completed the Computing with Integrity Tutorial on Moodle; and
8     3) I have achieved at least 80% in the Computing with Integrity Self Test.
9 I assert that this work is my own. I have appropriately acknowledged any and all material
10 (data, images, ideas or words) that I have used, whether directly quoted or paraphrased.
11 Furthermore, I certify that this assignment was prepared by me specifically for this course.
12 ****************************************************************************/
 
#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Food * createRecord(char * name, char * group, double calories, char theType)
{	
	Food * newFood;
	newFood = malloc(sizeof(Food));
	newFood->name = malloc(sizeof(char)*strlen(name)+1);
	strcpy(newFood->name, name);
	newFood->foodGroup = malloc(sizeof(char)*strlen(group)+1);
	strcpy(newFood->foodGroup, group);
	newFood->calories = calories;
	newFood->type = theType;
	newFood->next = NULL;

	/*For Debugging
	// printf("name: %s\n", newFood->name);
	// printf("Food Group: %s\n", newFood->foodGroup);
	// printf("calories: %f\n", newFood->calories);
	// printf("type: %c\n", newFood->type);*/

	return newFood;
}
	
char * printRecord(Food * toPrint)
{
	char * printFood;	

	printFood = malloc(sizeof(char)*1024);

	sprintf(printFood, "%s (%s):%.2f[%c]\n", toPrint->name, toPrint->foodGroup, toPrint->calories, toPrint->type);
	return printFood;
}

void destroyElement(Food * theElement)
{
	free(theElement->name);
	free(theElement->foodGroup);

}

Food * addToFront(Food * theList, Food * toBeAdded)
{
	toBeAdded->next = theList;
	return toBeAdded;
}

Food * addToBack(Food * theList, Food * toBeAdded)
{
	Food * tempPtr;
	tempPtr = theList;

	if (theList == NULL)
        {
		theList = toBeAdded;
		return theList;
	}

	while (tempPtr->next != NULL) 
        {
		tempPtr = tempPtr->next;
	}
	tempPtr->next = toBeAdded;

	return theList;
}

Food * removeFromFront(Food * theList)
{
	Food * tempPtr;
	tempPtr = theList;
	if (tempPtr == NULL)
        {
		return NULL;
	}
	tempPtr = theList->next;	
	theList = NULL;
	return tempPtr;
}

Food * removeFromBack(Food * theList)
{
	Food * tempPtr;
	tempPtr = theList;

	if (tempPtr == NULL)
        {
		return NULL;
	}

	if (theList->next == NULL)
        {
		tempPtr = NULL;
		return tempPtr;
	}

	while(tempPtr->next->next != NULL)
        {
		tempPtr = tempPtr->next;
	}
	tempPtr->next = NULL;
	return theList;
}

Food * getLastItem(Food * theList)
{
	Food * tempPtr;
	tempPtr = theList;
	if (isEmpty(theList))
        {
		return NULL;
	}
	else 
        {
		while(tempPtr->next != NULL)
                {
			tempPtr = tempPtr->next;
		}	
	}
	return tempPtr;
}

bool isEmpty(Food * theList)
{
	bool boolean;
	Food * tempPtr;
	tempPtr = theList;

	if (tempPtr == NULL)
        {
		boolean = true;
	}
	else 
        {
		boolean = false;
	}

	return boolean;
}

void printList(Food * theList)
{
	Food * tempPtr;
	char * printFood;
	tempPtr = theList;

	while (tempPtr != NULL)
        {
		printFood = printRecord(tempPtr);
		printf("%s",printFood);
		tempPtr = tempPtr->next;
	}
}

void destroyList(Food * theList)
{
    Food * tempPtr;
    Food * currPtr;
    tempPtr = theList;
    while (tempPtr != NULL)
    {
        currPtr = tempPtr;
        tempPtr = tempPtr->next;
        destroyElement(currPtr);
        free(currPtr);
    }
}


