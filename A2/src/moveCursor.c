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


#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include "moveCursor.h"

void movement(char *firstWord, long numInput, myStruct * ptrName)
{

    int oldX = ptrName->xPos;
    int oldY = ptrName->yPos;
    int i;

    /* Declaring all the colour pairs */
    start_color();
    init_pair(1, COLOR_RED, 7);
    init_pair(2, COLOR_GREEN, 7);
    init_pair(3, COLOR_YELLOW, 7);
    init_pair(4, COLOR_BLUE, 7);
    init_pair(5, COLOR_WHITE, 7);


   if (strcmp(firstWord, "setpencolor") == 0)
   {
        if (numInput == 1)
            ptrName->setPenColor = red;
        else if (numInput == 2) 
            ptrName->setPenColor = green;
        else if (numInput == 3) 
            ptrName->setPenColor = yellow;
        else if (numInput == 4)
            ptrName->setPenColor = blue;
        else 
            ptrName->setPenColor = white;
    }
    else if (strcmp(firstWord,"fd") == 0)    //90 DEGREE ANGLES FORWARD 
    {
        /* If the angle is any of these 2 (which are the same angle) then go in the direction 
        the angle (in this case its only up) for as much as the user entered.
        Assigns colour to the line and prints the line */
	if (ptrName->angle == 0 || ptrName->angle == 360)
        {
            for (i=0; i <= numInput; i++)
            {
                ptrName->yPos-=1;
                if (ptrName->pd==1) 
                { 
                    attron(COLOR_PAIR(ptrName->setPenColor));
                    mvaddch(ptrName->yPos,ptrName->xPos,'*');
                }
            }   
        }
        else if (ptrName->angle == 90 || ptrName->angle == -270) 
        {
            for (i=0; i <= numInput; i++)
            {
                ptrName->xPos+=1;
                if (ptrName->pd==1) 
                {
                    attron(COLOR_PAIR(ptrName->setPenColor)); 
                    mvaddch(ptrName->yPos,ptrName->xPos,'*');
                }
            }
        }
        else if (ptrName->angle == 180 || ptrName->angle == -180)
        {
            for (i=0; i <= numInput; i++)
            {
                ptrName->yPos+=1;
                if (ptrName->pd==1) 
                {
                    attron(COLOR_PAIR(ptrName->setPenColor)); 
                    mvaddch(ptrName->yPos,ptrName->xPos,'*');
                }
            }
        }
        else if (ptrName->angle == 270 || ptrName->angle == -90)
        {
            for (i=0; i <= numInput; i++)
            {
                ptrName->xPos-=1;
                if (ptrName->pd==1) 
                {
                    attron(COLOR_PAIR(ptrName->setPenColor)); 
                    mvaddch(ptrName->yPos,ptrName->xPos,'*');
                }
            }
        }

        if (ptrName->angle == 45 || ptrName->angle == -315)   // 45 DEGREE ANGLES FORWARD
        {
            for (i=0; i <= numInput; i++)
            {
                ptrName->yPos-=1;
                ptrName->xPos+=1;
                if (ptrName->pd==1) 
                {
                    attron(COLOR_PAIR(ptrName->setPenColor)); 
                    mvaddch(ptrName->yPos,ptrName->xPos,'*');
                }
            }   
        }
        else if (ptrName->angle == 135 || ptrName->angle == -225) 
        {
            for (i=0; i <= numInput; i++)
            {
                ptrName->xPos+=1;
                ptrName->yPos+=1;
                if (ptrName->pd==1) 
                {
                    attron(COLOR_PAIR(ptrName->setPenColor)); 
                    mvaddch(ptrName->yPos,ptrName->xPos,'*');
                }
            }
        }
        else if (ptrName->angle == 225 || ptrName->angle == -135)
        {
            for (i=0; i <= numInput; i++)
            {
                ptrName->yPos+=1;
                ptrName->xPos-=1;
                if (ptrName->pd==1) 
                {
                    attron(COLOR_PAIR(ptrName->setPenColor)); 
                    mvaddch(ptrName->yPos,ptrName->xPos,'*');
                }
            }
        }
        else if (ptrName->angle == 315 || ptrName->angle == -45)
        {
            for (i=0; i <= numInput; i++)
            {
                ptrName->xPos-=1;
                ptrName->yPos-=1;
                if (ptrName->pd==1) 
                { 
                    attron(COLOR_PAIR(ptrName->setPenColor));
                    mvaddch(ptrName->yPos,ptrName->xPos,'*');
                }
            }
        }
        if (ptrName->angle == 30 || ptrName->angle == -330) //30 DEGREE ANGLES Forward
        {
            for (i=0; i <= numInput; i++)
            {
                ptrName->yPos-=1;
                ptrName->xPos+=2;
                if (ptrName->pd==1) 
                { 
                    attron(COLOR_PAIR(ptrName->setPenColor));
                    mvaddch(ptrName->yPos,ptrName->xPos,'*');
                }
            }   
        }
        else if (ptrName->angle == 60 || ptrName->angle == -300) 
        {
            for (i=0; i <= numInput; i++)
            {
                ptrName->xPos+=1;
                ptrName->yPos-=2;
                if (ptrName->pd==1) 
                {
                    attron(COLOR_PAIR(ptrName->setPenColor)); 
                    mvaddch(ptrName->yPos,ptrName->xPos,'*');
                }
            }
        }
        else if (ptrName->angle == 120 || ptrName->angle == -240)
        {
            for (i=0; i <= numInput; i++)
            {
                ptrName->yPos-=2;
                ptrName->xPos-=1;
                if (ptrName->pd==1) 
                {
                    attron(COLOR_PAIR(ptrName->setPenColor)); 
                    mvaddch(ptrName->yPos,ptrName->xPos,'*');
                }
            }
        }
        else if (ptrName->angle == 150 || ptrName->angle == -210)
        {
            for (i=0; i <= numInput; i++)
            {
                ptrName->yPos-=1;
                ptrName->xPos-=2;
                if (ptrName->pd==1) 
                {
                    attron(COLOR_PAIR(ptrName->setPenColor)); 
                    mvaddch(ptrName->yPos,ptrName->xPos,'*');
                }
            }
        }
        else if (ptrName->angle == 210 || ptrName->angle == -150)
        {
            for (i=0; i <= numInput; i++)
            {
                ptrName->xPos-=2;
                ptrName->yPos+=1;
                if (ptrName->pd==1) 
                {
                    attron(COLOR_PAIR(ptrName->setPenColor)); 
                    mvaddch(ptrName->yPos,ptrName->xPos,'*');
                }
            }
        }
        else if (ptrName->angle == 240 || ptrName->angle == -120)
        {
            for (i=0; i <= numInput; i++)
            {
                ptrName->xPos-=1;
                ptrName->yPos+=2;
                if (ptrName->pd==1) 
                {
                    attron(COLOR_PAIR(ptrName->setPenColor)); 
                    mvaddch(ptrName->yPos,ptrName->xPos,'*');
                }
            }
        }
        else if (ptrName->angle == 300 || ptrName->angle == -60)
        {
            for (i=0; i <= numInput; i++)
            {
                ptrName->xPos+=1;
                ptrName->yPos+=2;
                if (ptrName->pd==1) 
                {
                    attron(COLOR_PAIR(ptrName->setPenColor)); 
                    mvaddch(ptrName->yPos,ptrName->xPos,'*');
                }
            }
        }
        else if (ptrName->angle == 330 || ptrName->angle == -30)
        {
            for (i=0; i <= numInput; i++)
            {
                ptrName->yPos+=1;
                ptrName->xPos+=2;
                if (ptrName->pd==1) 
                {
                    attron(COLOR_PAIR(ptrName->setPenColor)); 
                    mvaddch(ptrName->yPos,ptrName->xPos,'*');
                }
            }
        } 
    }
    else if (strcmp(firstWord, "bk") == 0)
    {
        if (ptrName->angle == 0 || ptrName->angle == 360)  //90 DEGREE ANGLES BACK
        {
            for (i=0; i <= numInput; i++)
            {
                ptrName->yPos+=1;
                if (ptrName->pd==1) 
                {
                    attron(COLOR_PAIR(ptrName->setPenColor)); 
                    mvaddch(ptrName->yPos,ptrName->xPos,'*');
                }
            }   
        }
        else if (ptrName->angle == 90 || ptrName->angle == -270)
        {
            for (i=0; i <= numInput; i++)
            {
                ptrName->xPos-=1;
                if (ptrName->pd==1) 
                {
                    attron(COLOR_PAIR(ptrName->setPenColor)); 
                    mvaddch(ptrName->yPos,ptrName->xPos,'*');
                }
            }
        }
        else if (ptrName->angle == 180 || ptrName->angle == -180)
        {
            for (i=0; i <= numInput; i++)
            {
                ptrName->yPos-=1;
                if (ptrName->pd==1) 
                {
                    attron(COLOR_PAIR(ptrName->setPenColor)); 
                    mvaddch(ptrName->yPos,ptrName->xPos,'*');
                }
            }
        }
        else if (ptrName->angle == 270 || ptrName->angle == -90)
        {
            for (i=0; i <= numInput; i++)
            {
                ptrName->xPos-=1;
                if (ptrName->pd==1) 
                {
                    attron(COLOR_PAIR(ptrName->setPenColor)); 
                    mvaddch(ptrName->yPos,ptrName->xPos,'*');
                }
            }
        }

        if (ptrName->angle == 45 || ptrName->angle == -315)   // 45 DEGREE ANGLES BACK
        {
            for (i=0; i <= numInput; i++)
            {
                ptrName->yPos+=1;
                ptrName->xPos-=1;
                if (ptrName->pd==1) 
                {
                    attron(COLOR_PAIR(ptrName->setPenColor)); 
                    mvaddch(ptrName->yPos,ptrName->xPos,'*');
                }
            }   
        }
        else if (ptrName->angle == 135 || ptrName->angle == -225) 
        {
            for (i=0; i <= numInput; i++)
            {
                ptrName->xPos-=1;
                ptrName->yPos-=1;
                if (ptrName->pd==1) 
                {
                    attron(COLOR_PAIR(ptrName->setPenColor)); 
                    mvaddch(ptrName->yPos,ptrName->xPos,'*');
                }
            }
        }
        else if (ptrName->angle == 225 || ptrName->angle == -135)
        {
            for (i=0; i <= numInput; i++)
            {
                ptrName->yPos-=1;
                ptrName->xPos+=1;
                if (ptrName->pd==1) 
                {
                    attron(COLOR_PAIR(ptrName->setPenColor)); 
                    mvaddch(ptrName->yPos,ptrName->xPos,'*');
                }
            }
        }
        else if (ptrName->angle == 315 || ptrName->angle == -45)
        {
            for (i=0; i <= numInput; i++)
            {
                ptrName->xPos+=1;
                ptrName->yPos+=1;
                if (ptrName->pd==1) 
                { 
                    attron(COLOR_PAIR(ptrName->setPenColor));
                    mvaddch(ptrName->yPos,ptrName->xPos,'*');
                }
            }
        }
        if (ptrName->angle == 30 || ptrName->angle == -330)  //30 DEGREE ANGLES BK
        {
            for (i=0; i <= numInput; i++)
            {
                ptrName->yPos+=1;
                ptrName->xPos-=2;
                if (ptrName->pd==1) 
                { 
                    attron(COLOR_PAIR(ptrName->setPenColor));
                    mvaddch(ptrName->yPos,ptrName->xPos,'*');
                }
            }   
        }
        else if (ptrName->angle == 60 || ptrName->angle == -300) 
        {
            for (i=0; i <= numInput; i++)
            {
                ptrName->xPos-=1;
                ptrName->yPos+=2;
                if (ptrName->pd==1) 
                {
                    attron(COLOR_PAIR(ptrName->setPenColor)); 
                    mvaddch(ptrName->yPos,ptrName->xPos,'*');
                }
            }
        }
        else if (ptrName->angle == 120 || ptrName->angle == -240)
        {
            for (i=0; i <= numInput; i++)
            {
                ptrName->yPos+=2;
                ptrName->xPos+=1;
                if (ptrName->pd==1) 
                {
                    attron(COLOR_PAIR(ptrName->setPenColor)); 
                    mvaddch(ptrName->yPos,ptrName->xPos,'*');
                }
            }
        }
        else if (ptrName->angle == 150 || ptrName->angle == -210)
        {
            for (i=0; i <= numInput; i++)
            {
                ptrName->yPos+=1;
                ptrName->xPos+=2;
                if (ptrName->pd==1) 
                {
                    attron(COLOR_PAIR(ptrName->setPenColor)); 
                    mvaddch(ptrName->yPos,ptrName->xPos,'*');
                }
            }
        }
        else if (ptrName->angle == 210 || ptrName->angle == -150)
        {
            for (i=0; i <= numInput; i++)
            {
                ptrName->xPos+=2;
                ptrName->yPos-=1;
                if (ptrName->pd==1) 
                {
                    attron(COLOR_PAIR(ptrName->setPenColor)); 
                    mvaddch(ptrName->yPos,ptrName->xPos,'*');
                }
            }
        }
        else if (ptrName->angle == 240 || ptrName->angle == -120)
        {
            for (i=0; i <= numInput; i++)
            {
                ptrName->xPos+=1;
                ptrName->yPos-=2;
                if (ptrName->pd==1) 
                {
                    attron(COLOR_PAIR(ptrName->setPenColor)); 
                    mvaddch(ptrName->yPos,ptrName->xPos,'*');
                }
            }
        }
        else if (ptrName->angle == 300 || ptrName->angle == -60)
        {
            for (i=0; i <= numInput; i++)
            {
                ptrName->xPos-=1;
                ptrName->yPos-=2;
                if (ptrName->pd==1) 
                {
                    attron(COLOR_PAIR(ptrName->setPenColor)); 
                    mvaddch(ptrName->yPos,ptrName->xPos,'*');
                }
            }
        }
        else if (ptrName->angle == 330 || ptrName->angle == -30)
        {
            for (i=0; i <= numInput; i++)
            {
                ptrName->yPos-=1;
                ptrName->xPos-=2;
                if (ptrName->pd==1) 
                {
                    attron(COLOR_PAIR(ptrName->setPenColor)); 
                    mvaddch(ptrName->yPos,ptrName->xPos,'*');
                }
            }
        }
    }
    else if (strcmp(firstWord,"rt") == 0) //increment in the right direction 
    {
        ptrName->angle += numInput;
    }
    else if (strcmp(firstWord, "lt") == 0) //decrement in the right direction (left)
    {
        ptrName->angle -= numInput;
    } 
    else if (strcmp(firstWord, "pu") == 0) //Boolean Var for pen down
    {
       ptrName->pd = 0;
    } 
    else if (strcmp(firstWord,"pd") == 0) 
    {
        ptrName->pd = 1;
    } 
    else if (strcmp(firstWord,"home") == 0) //resets back to center of screen
    {
        ptrName->yPos = 13;
        ptrName->xPos = 37; 
        ptrName->angle = 0;
        attron(COLOR_PAIR(ptrName->setPenColor));
        mvaddch(oldY,oldX,'*');
        mvaddch(ptrName->yPos,ptrName->xPos,'@');
    }
    else 
    {
        mvwprintw(stdscr, 32, 40,"I dont know how to %s",firstWord);
    }

    if (strcmp(firstWord,"st") == 0) //Boolean var for hide and show turtle
    {
        ptrName->tStatus = 1;
    }
    else if (strcmp(firstWord,"ht") == 0)
    {
        ptrName->tStatus = 0;
    }

    mvaddch(oldY,oldX,'*');
    attron(COLOR_PAIR(ptrName->setPenColor));

    if (ptrName->tStatus == 1)
    {
        mvaddch(ptrName->yPos, ptrName->xPos, '@');
    }
    else if (ptrName->tStatus == 0)
    {
        mvaddch(ptrName->yPos, ptrName->xPos, '*');
    }
    else
    {
        mvaddch(ptrName->yPos, ptrName->xPos, '@');
    }

    attroff(COLOR_PAIR(ptrName->setPenColor));
    refresh();
}

/* Currently does not work */ 
int checkBounds(myStruct * ptrName)
{
    if (ptrName->yPos > 24)
        return 0;
    else if (ptrName->yPos < 2)
        return 0;
    else if (ptrName->xPos > 69)
        return 0;
    else if (ptrName->xPos < 6)
        return 0;
    else
        return 1;
}
