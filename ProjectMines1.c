#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//#include<time.h>
#include<ctype.h>

#define size 5

void randomiser(int x[size][size])
{
    //Can change the code for randomiser
    //Since its not truly random
    int i,j,val;
    for(i=0; i<size; i++){
        for(j=0; j<size;j++){
            val = rand()/rand();
            if(val==0) x[i][j] = 1;
            else x[i][j] = 0;
        }
    }
}

void display(int x[size][size])
{
    int i,j,k;
    
    for(i=0; i<size; i++){
        if(i==0){
            printf(":)\t|");  
            for(k=1; k<size+1; k++){ 
                printf("%d\t",k);
                //Column numbers for user's reference
            }
            printf("\n\t|");
            for(k=0; k<size-1; k++) printf("_________");
        }
        printf("\n%d\t|",i+1);
        //Row numbers for user's reference
        for(j=0; j<size; j++){
            printf("%d \t", x[i][j]);
        }
        printf("\n\t|");        
    }
    //printf("\n");
    for(k=0; k<size-1; k++) printf("_________");
    printf("\n\n");
}

int calculate(int x[size][size], int y[size][size], int *count)
{
    int i,j,disp=0;
    for(i=0; i<size; i++){
        for(j=0; j<size; j++){
            disp = 0;
            //printf("%d%d ",i,j);
            //printf("%d\n",x[i][j]);

            //checking same column
            if(x[i-1][j]==1 && i!=0) disp++;
            if(x[i+1][j]==1 && i!=size-1) disp++;

            //checking same row
            if(x[i][j-1]==1 && j!=0) disp++;
            if(x[i][j+1]==1 && j!=size-1) disp++;

            //checking prev row
            if(x[i-1][j-1]==1 && i!=0 && j!=0) disp++;
            if(x[i-1][j+1]==1 && i!=0 && j!=size-1) disp++;
                
            //checking next row
            if(x[i+1][j-1]==1 && j!=0 && i!=size-1) disp++;
            if(x[i+1][j+1]==1 && i!=size-1 && j!=size-1) disp++;

            if(x[i][j]==1){
                y[i][j] = 0;  //The mines are 0s
                count++;
            }
            else y[i][j] = disp;
        }
        
    }
}

void create(char x[size][size])
{
    int i,j;
    for(i=0; i<size; i++){
        for(j=0; j<size; j++){
            x[i][j] = '?' ;
        }
    }
}

void display1(char x[size][size])
{
    int i,j,k;
    for(i=0; i<size; i++){
        if(i==0){
            printf(":)\t|"); 
            for(k=1; k<size+1; k++){ 
                printf("%d\t",k);
                //Column numbers for user's reference
            }
            printf("\n\t|");
            for(k=0; k<size-1; k++) printf("_________");
            //printf("-")
        }
        printf("\n%d\t|",i+1); 
        //Row numbers for user's reference
        for(j=0; j<size; j++){
            printf("%c \t", x[i][j]);
        }
        printf("\n\t|");
    }
    for(k=0; k<size-1; k++) printf("_________");
    printf("\n\n");
}

int main()
{
    int mines[size][size], clue[size][size], count=0;
    char frontEnd1[size][size], frontEnd2[size][size];
    randomiser(mines);
    //display(mines);
    
    calculate(mines, clue, &count);
    display(clue);
    
    create(frontEnd2);
    display1(frontEnd2);
    
    int row, column;
    char choice;

    printf("%d", count);

    printf("Enter the row and column number to dig: ");
    scanf("%d%d",&row,&column);
    //making sure the first cell selected isnt a mine
    //By changing the selected cell into 0 in the base array itself
    mines[row-1][column-1] = 0;
    //display(clue);

    while(1)
    {
        printf("Enter 'F' to place a flag and 'X' to dig a spot: ");
        scanf("%s",&choice);
        choice = toupper(choice);
        //putchar(choice);

        switch(choice)
        {
            case 'X' :
                printf("Enter the row and column number: ");
                scanf("%d%d",&row,&column);

            case 'F' :
            default : 
        }
        exit(0);
    }

}