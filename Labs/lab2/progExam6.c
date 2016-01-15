#include <string.h>
#include <stdio.h>

int main()
{
    char userInput[50];
    printf("Please enter a sentence: ");

    fgets(userInput, sizeof(userInput), stdin);

    int inputLength;
    inputLength = strlen(userInput);
    int i;
    for (i = 0; i < inputLength; i++)
    {
        if (userInput[i] == '9')
        {
            printf("true \n");
        }
    }
    return (0);
}
