#include <stdio.h>
#include <string.h>


typedef struct myStruct
{
   char areaCode[100];
   char phoneNumber[100];
   char type[100];

} myStruct;

void init(myStruct number);
void printMe(myStruct number);

int main(void)
{
    myStruct number;

    printf("My name is Kushal Pandya \n");

    init(number);
    printMe(number);
}

void init(myStruct number)
{
    number.areaCode["302"];
    number.phoneNumber["9712307"];
    number.type["land"];
}

void printMe(myStruct number)
{
    printf("Phone Number: (%s)-", number.areaCode);
    printf("%s \n", number.phoneNumber);
    printf("type: %s \n", number.type);
}
