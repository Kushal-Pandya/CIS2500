
# Flags that are sent to the compiler
# Do not change these
CFLAGS      =	-Wall  -pedantic -g -Iinclude


diary:
	gcc -lm $(CFLAGS)  src/main.c src/foodDiary.c src/linkedList.c -o bin/runMe

test: 
	gcc -lm $(CFLAGS) src/main.c src/foodDiary.c src/linkedList.c  -o bin/listTest

clean:
	@ rm *.o
