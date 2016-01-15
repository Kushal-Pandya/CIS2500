#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* argv and argc
 argc-- count (integer)
 argv char * * array.. array of strings
*/

int main (int argc, char * argv[])
{
    FILE * fileptr;
    

    if (argc == 2)
    {
        printf("%d\n", argc);

        int i;
        for (i=0; i<argc; i++)
        {
        
        }
    }
    else if (argc != 3)
    {
        printf("Not enough arguments \n");
    } 
    
    if (strcmp(argv[1], "-e") == 0)
    {
        printf("argument is -e %s\n", argv[1]);
    }
    else if (strcmp(argv[2], "-e") == 0)
    {
        printf("argument is -e2 %s\n", argv[2]);
    }
    
    
    if (strcmp(argv[1], "-f") == 0)
    {
        fileptr = fopen(argv[2], "r");
        if (fileptr != NULL)
        {
            printf("success \n");
        }
        else
        {
            exit(0);
        }
    }
    fclose(text.txt);
    return 0;

}