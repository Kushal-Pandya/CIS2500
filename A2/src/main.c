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
#include "moveCursor.h"

int main()
{
    char userInput[100];
    char *firstWord;
    char *secondWord;
    long numInput;
    int boundsCheck;
    myStruct * ptrName; 
    ptrName = malloc(sizeof(myStruct));

     initscr();

    drawInterface();

    ptrName->yPos = 13; //This is the center of the interface
    ptrName->xPos = 37;

    ptrName->angle = 0;
    ptrName->pd = 1; //Pen is down
    ptrName->tStatus = 1; //Turtle is not hidden

    mvaddch(ptrName->yPos,ptrName->xPos,'@');
    
     do
    {
        mvwprintw(stdscr, 27, 47, "Message Board ");
        mvwprintw(stdscr, 27, 8, "Input? ");
        getstr(userInput);
        mvwprintw(stdscr, 30, 40,"You entered: %s",userInput);

        /*Splitting the user input*/
        firstWord = strtok(userInput, " ");
        secondWord = strtok(NULL, " ");
        
        if (secondWord!=NULL) 
        { 
            numInput = atol(secondWord); //converting to integer
        }
    
        clearLine(27,8);

        boundsCheck = checkBounds(ptrName); //checking the bounds (DOES NOT WORK YET)

        if (boundsCheck == 1)
        {
            movement(firstWord, numInput, ptrName);
        }

        
        refresh();

    }while (strcmp(userInput,"quit")!=0);

    refresh();
    endwin();
    free(ptrName);

    return 0;
}




