1 Kushal Pandya                                   Student Number: 0888884
2 CIS 2500                                                a3.c 
3 March Friday 13th

ROGUE

5 *************
6 Compiling the program
7 *************
8 - this program is compiled by typing the following command on the cmd line: make
9 
10 *************
11 Running the program
12 *************
13 Start by entering the filename into the command line: rooms.txt
	The program will start when executed and will draw 6 rooms (sometimes results in seg fault) 
	the user has to enter commands which include: w,a,s,d and q for up, down, left, right and quit
	the hero will move accordingly to the input
	exit the program by typing "quit" twice
18 *************
19 Known Limitations
20 *************
 1) the buffer file can only be maximum of 100 characters 
 2) Maximum room sizes are 20x25 
 3) Need to enter q twice to quit
 4) If the room size (rows or cols) is double digits, it will not parse
 5) If any item coordinates (y or x) is double digits, it will not parse
 6) May somtimes result in segmentation fault

Important Information
- I have used code from my previous assignment (a1) for bounds checking and hero moving
	