/*************************A1.c****************************
2 Student Name: Kushal Pandya                        Student Number: 0888884
3 Date: January 16 2015                         Course Name: cis2500
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

#define UP 'i'
#define DOWN 'k'
#define LEFT 'j'
#define RIGHT 'l'
#define QUIT 'q'
#define SELECT 'x'

int gamePlay(char* playerOne, char* playerTwo);
void drawGrid ();
int checkBounds(int yPos, int xPos, int direction);

int main()
{

    char playerOne[10];
    char playerTwo[10];
    char mesgOne[50] = "Enter player one's name: ";
    char mesgTwo[50] = "Enter player two's name: ";

    initscr();
    mvprintw(13, 1,"%s",mesgOne);
    getstr(playerOne);
    mvprintw(14, 1,"%s",mesgTwo);
    getstr(playerTwo);

    cbreak();
    noecho();
    drawGrid();

    move(1,2);
    refresh();
    //when you first start the game, the cursor is first space (1,2)

    gamePlay(playerOne, playerTwo);

    refresh();
    getch();
    endwin();
    return 0;
}

int gamePlay(char* playerOne, char* playerTwo)
{
    int xPos = 2;
    int yPos= 1;
    int direction;

    /*int playerTurn;*/
    char playerCursor = 'X';


    /*Does not work*/
    /*for (playerTurn=1; playerTurn<=3; playerTurn++)
    {
        if(playerTurn == 2)
        {
            mvprintw(13, 30, "It is %s's turn \n", playerOne);
            playerCursor = 'X';
        }
        else if(playerTurn == 3)   
        {
            mvprintw(14, 30, "It is %s's turn \n", playerTwo);
            playerCursor = 'O';
            playerTurn = 1;
        }
    }*/
    

    do
    {      
        direction = getch();

        if (checkBounds(yPos, xPos, direction))
        {
            if (direction == UP)
                yPos-=2;
            if (direction == DOWN)
                yPos+=2;
            if (direction == RIGHT)
                xPos+=5;
            if (direction == LEFT)
                xPos-=5;
            if(direction == SELECT)
            {
                if (mvinch(yPos, xPos) == ' ')
                {
                    mvaddch(yPos,xPos, playerCursor);
                } 
            }
        }
        
        move(yPos, xPos);
        getyx(stdscr, yPos, xPos);

        /*Obstruction If statements*/
        if (mvinch(yPos, xPos) == playerCursor)
        {   
             mvaddch(yPos,xPos-5,'*');
             mvaddch(yPos-2,xPos,'*');
             mvaddch(yPos-2,xPos-5,'*');

            if (xPos + 5 < 27)
            {
                mvaddch(yPos,xPos+5,'*'); 
                mvaddch(yPos-2,xPos+5,'*');
            }
            if (yPos+2 < 11)
            {   
                mvaddch(yPos+2,xPos,'*');
                mvaddch(yPos+2,xPos-5,'*');
            } 
            if (yPos+2 < 11 && xPos < 27)
            {
                mvaddch(yPos+2,xPos+5,'*');
            }
        }
      
        refresh();
   
    }while (direction != QUIT);

    return 0;
}

int checkBounds(int yPos, int xPos, int direction)
{
    if(yPos+2 > 11 && direction == DOWN)
       return 0;
    else if (yPos-2 < 1 && direction == UP)
        return 0;
    else if (xPos+5 > 27 && direction == RIGHT)
        return 0;
    else if (xPos-5 < 2 && direction ==  LEFT)
        return 0;
    else 
        return 1;
}

void drawGrid()
{
    int i;
    int j;
    for(i=1;i<=11;i+=2)
    {
        for(j=0;j<=30;j+=5)
        {
            mvaddch(i,j,'|');
        }
    }
    for(i=0;i<=13;i+=2)
    {
        for(j=0; j<=30; j++)
        {
            mvaddch(i,j,'-');
        }
    }
    refresh();
}
