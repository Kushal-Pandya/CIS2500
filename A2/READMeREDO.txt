 1 Kushal Pandya                                   Student Number: 0888884
2 CIS 2500                                                a2.c 
3 February Friday 13th

	LOGO INTREPRETOR


5 *************
6 Compiling the program
7 *************
8 - this program is compiled by typing the following command on the cmd line: make
9 
10 *************
11 Running the program
12 *************
13 The program will start when executed and will spawn the cursor at the input box
	the user has to enter commands which include: fd, bk, st, ht, lt, rt, home, pu, pd, quit and setpencolor
	the cursor will move accordingly to the input
	exit the program by typing "quit"
18 *************
19 Known Limitations
20 *************
21 the input can only ba maximum of 100 characters 
	the boundaries of the interface do not prevent the cursor from leaving 
	file saving results in a segmentation fault
	can only enter some commands which are listed above
	only pressing enter without a command results in segmentation fault
	setting colour back to white will result in a grayish colour not white
******************************
Enhancements (more than 80%)
******************************
- used home function to set cursor where it started
- implemented st and ht
****************************
Redo What I did differently
****************************
- made bounds check work 
- cleared code of cpplint errors (lost all 5 marks last time)
 