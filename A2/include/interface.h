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

#ifndef _PANDYAK_INTERFACEH  
#define _PANDYAK_INTERFACEH 

#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

/*
 Pre: None
 Post: The function prints out the interface along with the input box and message box
*/
void drawInterface();

/*
 Pre: takes in a new set of coordinates of y and x
 Post: clears the line of the input and message box
*/
void clearLine(int y, int x);

#endif
