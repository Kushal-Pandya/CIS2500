/*************************A2.c****************************
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

#include "main.h"
#include "linkedList.h"

void fileCheck(char *fileName)
{
	char buffer[200];
	FILE * fileptr;
	char *name;
	char *foodGroup;
	char * token;
  char type;
	double numCal;

	Food * currentFood;
	Food * listFood;

	listFood = malloc(sizeof(Food));
  listFood = NULL;

  fileptr = fopen(fileName,"r");

  if (fileptr == NULL) 
  {
  	printf("No File to read\n");
  	exit(0);
  }


  /*Parsing the input file*/
  while (fgets(buffer, 200, fileptr)!= NULL)
   {
      name = strtok(buffer, ",");
      foodGroup = strtok(NULL, ",");
      token = strtok(NULL, ",");
      numCal = atof(token);
      token = strtok(NULL, ",");
      type = token[0];
      currentFood = createRecord(name, foodGroup, numCal, type);

      if (type == 'h')
      {
       	listFood = addToFront(listFood, currentFood);
      }
      else if (type == 'j')
      {
      	listFood = addToBack(listFood, currentFood);
      }      
	}

  /*calling rest of the functions*/
  sumCal(listFood);
  avgCal(listFood);
  printList(listFood);
  destroyList(listFood);

}

void sumCal(Food * theList)
{
  Food * tempPtr;
  double totalCal;
  double roundedCal; 
  tempPtr = theList;
  totalCal = 0;

  /*While tempPtr is not empty it will increment and sum the calories*/
  while (tempPtr != NULL)
  { 
    totalCal = totalCal + tempPtr->calories;
    tempPtr = tempPtr->next;
  }

  roundedCal = ceil(totalCal);
  printf("%.0f \n", roundedCal);
}

void avgCal(Food * theList)
{
  Food * tempPtr;
  double vegTotalCal = 0;
  double meatTotalCal = 0;
  double dairyTotalCal = 0;
  double grainsTotalCal = 0;
  double fatTotalCal = 0;
  int vegCount = 0;
  int meatCount = 0;
  int dairyCount = 0;
  int grainsCount = 0;
  int fatCount = 0;
  double vegAvg;
  double meatAvg;
  double dairyAvg;
  double grainsAvg;
  double fatAvg;

  tempPtr = theList;

  /*checking to see if there the string compares with the foodgroup and increment the calories with the count*/
  while (tempPtr != NULL)
  { 
    if (strcmp(tempPtr->foodGroup, "vegfruit") == 0)
    {
      vegTotalCal = vegTotalCal + tempPtr->calories;
      vegCount++;
    }
    else if (strcmp(tempPtr->foodGroup, "meat") == 0)
    {
      meatTotalCal = meatTotalCal + tempPtr->calories;
      meatCount++;
    }
    else if (strcmp(tempPtr->foodGroup, "dairy") == 0)
    {
      dairyTotalCal = dairyTotalCal + tempPtr->calories;
      dairyCount++;
    }
    else if (strcmp(tempPtr->foodGroup, "grains") == 0)
    {
      grainsTotalCal = grainsTotalCal + tempPtr->calories;
      grainsCount++;
    }
    else if (strcmp(tempPtr->foodGroup, "fat") == 0)
    {
      fatTotalCal = fatTotalCal + tempPtr->calories;
      fatCount++;
    }
    tempPtr = tempPtr->next;
  }

    /*Printing the calories*/  
    vegAvg = vegTotalCal/vegCount;
    if (vegTotalCal != 0 || vegCount != 0)
      printf("%.2f\n", vegAvg);
    else
      printf("0.00\n");

    meatAvg = meatTotalCal/meatCount;
    if (meatTotalCal != 0 || meatCount != 0)
      printf("%.2f\n", meatAvg);
    else
      printf("0.00\n");

    dairyAvg = dairyTotalCal/dairyCount;
    if (dairyTotalCal != 0 || dairyCount != 0)
      printf("%.2f\n", dairyAvg);
    else
      printf("0.00\n");

    grainsAvg = grainsTotalCal/grainsCount;
    if (grainsTotalCal != 0 || grainsCount != 0)
      printf("%.2f\n", grainsAvg);
    else
      printf("0.00\n");

    fatAvg = fatTotalCal/fatCount;
    if (fatTotalCal != 0 || fatCount != 0)
      printf("%.2f\n", fatAvg);
    else
      printf("0.00\n");
}

