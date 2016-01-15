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


#ifndef BOOL_DEF
#define BOOL_DEF
/*Judi's home made bool type.*/
typedef int bool;
enum {false, true};
#endif
#ifndef _judi_LINKEDLISTH
#define _judi_LINKEDLISTH

/***************************************
struct and operations that work directly on the struct
The struct operations and definition could be in their 
own .c and .h files (and sometimes should be). For the purposes of
this assignment, please leave the struct definition here
****************************************/


struct Food{
 char * name;
 char * foodGroup;
 double calories;
 char type;
 struct Food * next;
};

/*do not remove this typedef. We need it for testing your code */

typedef struct Food Food;


/******************************
 Functions operating on structs 
 *******************************/

/*This function takes in two strings for name and food group, the number of calories 
the food contained and a single character representing the type of food (h for healthy, j for junk). 
The function allocates memory for the struct, initializes the variables to the supplied
values, initializes the next pointer to null and returns a pointer to the allocated memory. 
Returns NULL on failure.The value for name and group are copied into newly allocated memory.
The passed-in memory for name and group must be freed elsewhere in the program.
Memory for the struct must be freed elsewhere in the program. 
*/
Food * createRecord(char * name, char * group, double calories, char theType);


/*This function takes a pointer to a food linked list element and returns a pointer to a string 
that contains the information from the struct formatted
in the following manner: "Name (Food Group):calories[type] The string should not 
contain a newline. Calories should be reported to two decimal places, padding where necessary.
The string memory is allocated in this function and must be freed elsewhere in 
the program.
*/
char * printRecord(Food * toPrint);


/*Takes a pointer to a list element and frees the memory for the internal variables.
the struct itself must be freed separately */
void destroyElement(Food * theElement);

/********************************
List operations
*********************************/


/*addToFront(Food * theList, Food * toBeAdded)
Takes a pointer to the head of the list and an initialized list 
element. Adds the element to the front of the linked list and
returns a pointer to the new head of the list. */
Food * addToFront(Food * theList, Food * toBeAdded);


/*addToBack(Food * theList, Food * toBeAdded)
Takes a pointer to the head of the list and an initialized list 
element. Adds the element to the back of the linked list and
returns a pointer to the head of the list. */
Food * addToBack(Food * theList, Food * toBeAdded);


/*removeFromFront(Food * theList)
Takes a pointer to the head of the list. Removes the front
item from the head of the list. Does not free the memory for 
the item removed. Returns a pointer to the head of the list.
Returns NULL if the list is empty*/
Food * removeFromFront(Food * theList);


/*removeFromBack(Food * theList)
Takes a pointer to the head of the list. Removes the last
item from the head of the list. Does not free the memory for 
the item removed. Returns a pointer to the head of the list.
Returns NULL if the list is empty.
*/
Food * removeFromBack(Food * theList);


/*getLastItem(Food * theList)
Takes a pointer to the head of the list. Returns 
a pointer to the item at the end of the list.
Returns NULL if the list is empty.
*/
Food * getLastItem(Food * theList);


/*isEmpty(Food * theList)
Takes a pointer to the head of the list. Returns 
true if the list is empty and false 
if the list has elements.
*/
bool isEmpty(Food * theList);


/*printList(Food * theList)
Takes a pointer to the head of the list. Prints to stdout
 all of the elements of the list (formatted 
as specified for the printRecord function) separated by newlines.
*/
void printList(Food * theList);


/*destroyList(Food * theList)
Takes a pointer to the list and frees the memory for each struct in the list.
Handles an empty list gracefully.
*/
void destroyList(Food * theList);

#endif
