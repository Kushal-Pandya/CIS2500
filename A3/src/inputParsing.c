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

void inputParser(char * buffer, Room * roomPtr, int counter, Item ** itemPtr, Hero * hero)
{
	char *token;
	char * length;
    char * width; 

    length = strtok(buffer, "X");
    width = strtok(NULL, " ");

    roomPtr->length = atol(length);
    roomPtr->width = atol(width);

   // printf("length of room: %d\n", roomPtr->length);
    //printf("width of room: %d\n", roomPtr->width);

    //checking to see which room it is
    if (counter == 0) 
    {
    	roomPtr->x = 2;
    	roomPtr->y = 2;
    } 
    else if (counter==1)
    {
    	roomPtr->x = 27;
    	roomPtr->y = 2;
    } 
    else if (counter==2) 
    {
    	roomPtr->x = 57;
    	roomPtr->y = 2;
    } 
    else if (counter==3) 
    {
    	roomPtr->x = 2;
    	roomPtr->y = 27;
    } 
    else if (counter==4) 
    {
    	roomPtr->x = 27;
    	roomPtr->y = 27;
    } 
    else if (counter==5) 
    {
    	roomPtr->x = 57;
    	roomPtr->y = 27;	
    }

    //Parsing while loop with strtok
    token = strtok(NULL, " ");
    while (token)
    {
    	getElementToken(token, roomPtr, itemPtr, hero);
    	token = strtok(NULL, " ");
    }

}

void getElementToken (char * element, Room * roomPtr, Item ** itemPtr, Hero * hero) 
{
	char firstLetter = element[0];
	char cDirection;
	char cPos;
	int cX;
	int cY;
	switch (firstLetter) 
        {
		// if its a a door, i check to see what direction its in and then add it to the item array
		case 'd':
			hero->itemCounter++;
			itemPtr[hero->itemCounter] = malloc(sizeof(Item));
			cDirection = element[1];
			cPos = element[2];
			//printf("Input String real: %s\n", element);
			switch (cDirection) 
		        {
				case 'n':
					itemPtr[hero->itemCounter]->xPos = (cPos - '0') + roomPtr->x;
					itemPtr[hero->itemCounter]->yPos = roomPtr->y;
					//printf("x:%d, y:%d\n",itemPtr[hero->itemCounter]->xPos,itemPtr[hero->itemCounter]->yPos);
					break;
				case 'e':
					itemPtr[hero->itemCounter]->xPos = roomPtr->x + roomPtr->length;
					itemPtr[hero->itemCounter]->yPos = roomPtr->y + (cPos - '0');
					//printf("x:%d, y:%d\n",itemPtr[hero->itemCounter]->xPos,itemPtr[hero->itemCounter]->yPos);
					break;
				case 'w':
					itemPtr[hero->itemCounter]->xPos = roomPtr->x;
					itemPtr[hero->itemCounter]->yPos = roomPtr->y + (cPos - '0');
					//printf("x:%d, y:%d\n",itemPtr[hero->itemCounter]->xPos,itemPtr[hero->itemCounter]->yPos);
					break;
				case 's':
					itemPtr[hero->itemCounter]->xPos = roomPtr->x + (cPos - '0');
					itemPtr[hero->itemCounter]->yPos = roomPtr->y + roomPtr->width;
					//printf("x:%d, y:%d\n",itemPtr[hero->itemCounter]->xPos,itemPtr[hero->itemCounter]->yPos);
					break;
			}
			mvaddch(itemPtr[hero->itemCounter]->yPos, itemPtr[hero->itemCounter]->xPos, '+');
			//printf("Door element found\n");
			break; 
			// performing same actions as the door algorithm
		case 'h':
			cY = element[1];
			cX = element[2];
			hero->y = cY - '0' + roomPtr->y;
			hero->x = cX - '0'+ roomPtr->x;
			mvaddch(hero->y, hero->x, '@');
			//printf("hero y:%d, hero x:%d\n",hero->y,hero->x);
			//printf("Hero element found\n");
			break;
		case 'M':
			hero->itemCounter++;
			itemPtr[hero->itemCounter] = malloc(sizeof(Item));

			cY = element[1];
			cX = element[2];
			itemPtr[hero->itemCounter]->yPos= cY - '0' + roomPtr->y;
			itemPtr[hero->itemCounter]->xPos = cX - '0' + roomPtr->x;
			mvaddch(itemPtr[hero->itemCounter]->yPos, itemPtr[hero->itemCounter]->xPos, 'M');
			//printf("Monster y:%d, Monster x:%d\n", itemPtr[hero->itemCounter]->yPos, itemPtr[hero->itemCounter]->xPos);
			//printf("Monster element found\n");
			break;
		case 'g':
			hero->itemCounter++;
			itemPtr[hero->itemCounter] = malloc(sizeof(Item));

			cY = element[1];
			cX = element[2];
			itemPtr[hero->itemCounter]->yPos= cY- '0' + roomPtr->y;
			itemPtr[hero->itemCounter]->xPos = cX - '0' + roomPtr->x;
			mvaddch(itemPtr[hero->itemCounter]->yPos, itemPtr[hero->itemCounter]->xPos, '*');
			//printf("Gold y:%d, Gold x:%d\n",itemPtr[hero->itemCounter]->yPos, itemPtr[hero->itemCounter]->xPos);
			//printf("Gold element found\n");
			break;
		case 'p':
			hero->itemCounter++;
			itemPtr[hero->itemCounter] = malloc(sizeof(Item));
			
			cY = element[1];
			cX = element[2];
			itemPtr[hero->itemCounter]->yPos= cY - '0' + roomPtr->y;
			itemPtr[hero->itemCounter]->xPos = cX - '0' + roomPtr->x;
			mvaddch(itemPtr[hero->itemCounter]->yPos, itemPtr[hero->itemCounter]->xPos, '!');
			//printf("Potion y:%d, Potion x:%d\n", itemPtr[hero->itemCounter]->yPos, itemPtr[hero->itemCounter]->xPos);
			//printf("Potion Element found\n");
			break;
		case 's':
			hero->itemCounter++;
			itemPtr[hero->itemCounter] = malloc(sizeof(Item));
			
			cY = element[1];
			cX = element[2];
			itemPtr[hero->itemCounter]->yPos= cY - '0' + roomPtr->y;
			itemPtr[hero->itemCounter]->xPos = cX - '0' + roomPtr->x;
			mvaddch(itemPtr[hero->itemCounter]->yPos, itemPtr[hero->itemCounter]->xPos, '%');
			//printf("Stairs y:%d, Stairs x:%d\n",itemPtr[hero->itemCounter]->yPos,itemPtr[hero->itemCounter]->xPos);
			//printf("Stairs Element found\n");
			break;
		case 'w':
			hero->itemCounter++;
			itemPtr[hero->itemCounter] = malloc(sizeof(Item));
			
			cY = element[1];
			cX = element[2];
			itemPtr[hero->itemCounter]->yPos= cY - '0' + roomPtr->y;
			itemPtr[hero->itemCounter]->xPos = cX - '0' + roomPtr->x;
			mvaddch(itemPtr[hero->itemCounter]->yPos, itemPtr[hero->itemCounter]->xPos, ')');
			//printf("Weapons y:%d, Weapons x:%d\n",itemPtr[hero->itemCounter]->yPos,itemPtr[hero->itemCounter]->xPos);
			//printf("Weapons Element found\n");
			break;
	}
}

