#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define size 5

void randomiser(int *x)
{
    //Can change the code for randomiser
    //Since its not truly random
    int i,j,val;
    for(i=0; i<size; i++){
        for(j=0; j<size;j++){
            val = rand()/rand();
            if(val==0) *((x+i)+j) = 1;
            else *((x+i)+j) = 0;
        }
    }
}

void display(int *x)
{
    int i,j;
    for(i=0; i<size; i++){
        for(j=0; j<size;j++){
            printf("%d \t", *((x+i)+j));
        }
        printf("\n\n");
    }
    printf("-----------------------------------\n");
}

void calculate(int *x, int *y)
{
    int i,j,disp=0;
    for(i=0; i<size; i++){
        for(j=0; j<size; j++){
                disp = 0;
                printf("%d%d ",i,j);
                printf("%d\n",*((x+i)+j));
                //checking same column
                if(*((x+i-1)+j)==1 && i!=0) disp++;
                if(*((x+i+1)+j)==1 && i!=size-1) disp++;

                //checking same row
                if(*((x+i)+j-1)==1 && j!=0) disp++;
                if(*((x+i)+j+1)==1 && j!=size-1) disp++;

                //checking prev row
                if(*((x+i-1)+j-1)==1 && i!=0 && j!=0) disp++;
                if(*((x+i-1)+j+1)==1 && i!=0 && j!=size-1) disp++;
                
                //checking next row
                if(*((x+i+1)+j-1)==1 && j!=0 && i!=size-1) disp++;
                if(*((x+i+1)+j+1)==1 && i!=size-1 && j!=size-1) disp++;

                *((y+i)+j) = disp;
            
        }
        
    }
}

int main()
{
    int mines[size][size];
    randomiser(*mines);
    display(*mines);
    
    int clue[size][size];
    calculate(*mines, *clue);
    display(*clue);
}