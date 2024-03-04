#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//#include<time.h>
#include<ctype.h>

int main()
{
    int row, column, brr;
    char choice;
    printf("Enter the row and column number: ");
    scanf("%d%d",&row,&column);

    printf("Enter 'F' to place a flag and 'X' to dig a spot: ");
    scanf("%s", &choice);
    choice = toupper(choice);
    putchar(choice);
}