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

void fileCheck(char *fileName)
{
	char buffer[100];
	int counter;
  int inputch;
	   
     //Iniializing all variables and pointers and arrays
	  FILE * fileptr;
  	fileptr = fopen("assets/room.txt","r");
  	Room * * roomPtr;
  	roomPtr = malloc(sizeof(Room*)*6);

  	Item * * itemPtr = malloc(sizeof(Item*)*100);
  	Hero * hero = malloc(sizeof(Hero));
  	hero->itemCounter = 0;

  	if (fileptr == NULL) 
        {
  		printf("No File to read\n");
  		exit(0);
  	}
  	counter = 0; 

  	while (fgets(buffer, 100, fileptr)!= NULL)
    {
    	roomPtr[counter] = malloc(sizeof(Room));
    	//printf("%s\n - Room:%d\n",buffer,counter);
      init();
  		inputParser(buffer, roomPtr[counter], counter,itemPtr,hero);
  		counter++;
      drawRooms(*roomPtr, itemPtr, hero);
  	}
    //initializing ncurses and playing the game

    
    playRogue(roomPtr, hero);

    inputch = getch();
    if (inputch!= 'q')
    {
        exit(0);
    } 
    refresh();
    endwin();
  	fclose(fileptr);
    free(roomPtr);
    free(itemPtr);
    free(hero);
  	
}

