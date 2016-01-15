/*************************A4.c************************************************
2 Student Name: Kushal Pandya                        Student Number: 0888884
3 Due Date: April 1 2015                             Course Name: cis2500
4 I have exclusive control over this submission via my password.
5 By including this statement in this header comment, I certify that:
6     1) I have read and understood the University policy on academic integrity;
7     2) I have completed the Computing with Integrity Tutorial on Moodle; and
8     3) I have achieved at least 80% in the Computing with Integrity Self Test.
9 I assert that this work is my own. I have appropriately acknowledged any and all material
10 (data, images, ideas or words) that I have used, whether directly quoted or paraphrased.
11 Furthermore, I certify that this assignment was prepared by me specifically for this course.
12 ****************************************************************************/

#ifndef _PANDYAK_MAINH  
#define _PANDYAK_MAINH 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "linkedList.h"

/*Receives file from main and parses string and sorts it */
void fileCheck(char * fileName);

/*Calculates sum of the calories*/
void sumCal(Food * theList);

/*Calculates average calories for each foodgroup*/
void avgCal(Food * theList);

#endif