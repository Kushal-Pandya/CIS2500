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

#ifndef _PANDYAK_MAINH  
#define _PANDYAK_MAINH 

#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

typedef struct myStruct
{
	int yPos;
	int xPos;
	char message[50];
}Item;

typedef struct myStructTwo
{
	int length;
	int width;
	int x;
	int y;
	int endX;
	int endY;
	// Item * itemArray;	
}Room;

typedef struct myStructThree
{
	int x;
	int y;
	int currentY;
	int currentX;
	Item * inventory;
	int itemCounter;
} Hero;

/*
 Pre: takes in the input buffer, room array item array and hero pointer
 Post: The function parses all input such as items and movement and sends to other functions
*/
void inputParser(char * buffer, Room * roomPtr, int counter,Item ** itemPtr, Hero * hero);

/*
 Pre: none
 Post: initializes ncurses
*/
void init();

/*
 Pre: takes in the input file
 Post: The function sends input information to parsing functions
*/
void fileCheck(char * fileName);

/*
 Pre: takes in the tokenized input, and all other pointers and arrays
 Post: The function adds parsed input onto items and hero to they can be printed
*/
void getElementToken(char *element, Room * roomPtr,Item ** itemPtr, Hero *hero);

/*
 Pre: takes room array item array and hero pointer
 Post: The function draws the rooms
*/
void drawRooms(Room * roomPtr, Item ** itemPtr, Hero * hero);

/*
 Pre: function takes in room array and hero pointer
 Post: The function allows the hero to move
*/
void playRogue(Room ** roomPtr, Hero * hero);

/*
 Pre: takes in the room array, direction of the movement and position of the hero
 Post: Function does not currently work but prevents user from leaving room
*/
int checkBounds(Hero * hero, int direction);

#endif