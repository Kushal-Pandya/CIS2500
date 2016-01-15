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

#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'
#define QUIT 'q'

void playRogue (Room ** roomPtr, Hero * hero)
{  
	// int xPos = 10;
 //    int yPos= 6;
    int oldX;
    int oldY;
    int direction; 	

    hero->y = 8;
    hero->x = 10;
    mvaddch(hero->y, hero->x, '@');

    do
    {    //Moving the hero

        oldY = hero->y;
        oldX = hero->x;
        direction = getch();

        if (checkBounds(hero, direction) == 1)
        {
            if (direction == UP)
                hero->y-=1;
            if (direction == DOWN)
                hero->y+=1;
            if (direction == RIGHT)
                hero->x+=1;
            if (direction == LEFT)
                hero->x-=1;
        }

        move(hero->y, hero->x);
        mvaddch(oldY, oldX, '.');
        mvaddch(hero->y, hero->x, '@');
        
        
        refresh();
    } while (direction != QUIT);
}

//Checking the bounds: results in seg fault 
int checkBounds(Hero * hero, int direction)
{
    if ((mvinch(hero->y-1, hero->x) != '-') && direction == UP)
       return 1;
    else if ((mvinch(hero->y+1, hero->x) != '-') && direction == DOWN)
        return 1;
    else if ((mvinch(hero->y, hero->x+1) != '|') && direction == RIGHT)
        return 1;
    else if ((mvinch(hero->y, hero->x-1) != '|') && direction == LEFT)
        return 1;
    else 
        return 0;
}
