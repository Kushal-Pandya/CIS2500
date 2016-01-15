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

void init()
{
	initscr();
	refresh();
	noecho();
	cbreak();

}

void drawRooms(Room * roomPtr, Item ** itemPtr, Hero * hero)
{
	int i; 
 	int j;


    //drawing the rooms
    for (i= roomPtr->y; i<= roomPtr->width+2; i++)
    {
        mvaddch(i,roomPtr->x,'|');
    }
    for (i=roomPtr->y; i<=roomPtr->width+1; i++)
    {
        mvaddch(i, roomPtr->x+roomPtr->length,'|');
    }
    for (i=roomPtr->x; i<=roomPtr->length+2; i++)
    {
        mvaddch(roomPtr->y-1,i,'-'); 
    }
    for (i=roomPtr->x; i<=roomPtr->length+2; i++)
    {
         mvaddch(roomPtr->y+roomPtr->width,i,'-'); 
    }
    for (i=roomPtr->x+1; i<roomPtr->length+2; i++)
    {
    	for (j=roomPtr->y; j<roomPtr->width+2; j++)
        {
     		mvaddch(j,i,'.');
     	}
     }
}

