#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
   FILE * fileptr;
   char buffer[50];
   
   if (argc < 2)
   {
       printf("no command line paramater\n");
       exit(0);
   }
   
   if (strcmp(argv[1], "text.txt") == 0)
   {
       fileptr = fopen(argv[1], "r");
       
       int i;
       while (fgets(buffer, 50, fileptr)!= NULL)
       {
           printf("%s", buffer);
       }
   }

   fclose(fileptr);
   return 0;
}