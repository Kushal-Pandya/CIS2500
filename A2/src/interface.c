/*************************A2.c****************************
2 Student Name: Kushal Pandya                   Student Number: 0888884
3 Date: February 13 2015                        Course Name: cis2500
4 I have exclusive control over this submission via my password.
5 By including this statement in this header comment, I certify that:
6     1) I have read and understood the University policy on academic integrity;
7     2) I have completed the Computing with Integrity Tutorial on Moodle; and
8     3) I have achieved at least 80% in the Computing with Integrity Self Test.
9 I assert that this work is my own. I have appropriately acknowledged any and all material
10 (data, images, ideas or words) that I have used, whether directly quoted or paraphrased.
11 Furthermore, I certify that this assignment was prepared by me specifically for this course.
12 ****************************************************************************/

#include "interface.h"

void drawInterface()
{
	int i;

    //Border Lines
    for (i=2;i<=24;i++)
    {
        mvaddch(i,5,'|');
    }
    for (i=2;i<=24;i++)
    {
        mvaddch(i,70,'|');
    }
    for (i=5;i<=70;i++)
    {
        mvaddch(1,i,'-'); 
    }
    for (i=5;i<=70;i++)
    {
        mvaddch(25,i,'-'); 
    }

    //Interface Input 
    for (i=27;i<=29;i++)
    {
        mvaddch(i,7,'|');
    }
    for (i=27;i<=29;i++)
    {
        mvaddch(i,29,'|');
    }
    for (i=7;i<=29;i++)
    {
        mvaddch(26,i,'-'); 
    }
    for (i=7;i<=29;i++)
    {
        mvaddch(29,i,'-'); 
    }

    //Message Board
    for (i=27;i<=36;i++)
    {
        mvaddch(i,38,'|');
    }
    for (i=27;i<=36;i++)
    {
        mvaddch(i,69,'|');
    }
    for (i=38;i<=69;i++)
    {
        mvaddch(26,i,'-'); 
    }
    for (i=38;i<=69;i++)
    {
        mvaddch(37,i,'-'); 
    }

    refresh();
}

void clearLine(int y, int x)
{

    mvwprintw(stdscr, y, x, "              ");
}
