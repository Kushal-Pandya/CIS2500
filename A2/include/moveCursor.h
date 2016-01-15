/*************************A2.c****************************
2 Student Name: Kushal Pandya                        Student Number: 0888884
3 Date: February 13 2015                             Course Name: cis2500
4 I have exclusive control over this submission via my password.
5 By including this statement in this header comment, I certify that:
6     1) I have read and understood the University policy on academic integrity;
7     2) I have completed the Computing with Integrity Tutorial on Moodle; and
8     3) I have achieved at least 80% in the Computing with Integrity Self Test.
9 I assert that this work is my own. I have appropriately acknowledged any and all material
10 (data, images, ideas or words) that I have used, whether directly quoted or paraphrased.
11 Furthermore, I certify that this assignment was prepared by me specifically for this course.
12 ****************************************************************************/

#ifndef _PANDYAK_MOVECURSORH  
#define _PANDYAK_MOVECURSORH 

#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

typedef enum myColors
{
    red = 1,
    green = 2,
    yellow = 3,
    blue = 4,
    white = 7
} Colour;

typedef struct myStruct
{
	int yPos;
	int xPos;
	int angle;
	int pd;
	int tStatus;
	Colour setPenColor;
} myStruct;

/*
 Pre: Takes in the struct 
 Post: Prevents the user from moving outside the interface (DOES NOT WORK YET)
*/
int checkBounds(myStruct * ptrName);


/*
 Pre: The function takes in the first word the user enters, the second word the user enters (which is converted into a string), 
 and the variable name from the struct 

 Post: the cursor is moved to a spot on the board with the logo inputs
 Also the colour attribute can be set as well as the cursor toggle
 The user can choose to draw with the pen or without and can return to the center of the scene
*/
void movement(char *firstWord, long numInput, myStruct * ptrName);


#endif
