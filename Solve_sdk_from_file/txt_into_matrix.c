#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void txt_into_matrix(int matrix[9][9],char PATH[])
{
    //initialisation of the pointer + attribution of the file that the pointer will point to
    FILE * fPointer;
    fPointer = fopen(PATH,"r");
    char line[12];

    int rows = 0;
    int column = 0;

    while(fgets(line,sizeof(line),fPointer))
    {
        for (size_t nth = 0; nth < strlen(line); nth++)
        {
            if (line[nth] == '.')
            {
                matrix[rows][column] = 0;
                column++;
            }

            if (line[nth] >= '1' && line[nth] <= '9') 
            {
                matrix[rows][column] = line[nth] - '0';
                column++;
            }
        }  
        
    }
    fclose(fPointer);
}


void matrix_into_txt(int matrix[9][9],char PATH[])
{
    //initialisation of the pointer + attribution of the file that the pointer will point to
    FILE * fPointer;
    fPointer = fopen(PATH,"w");
    
    for(size_t y = 0; y < 9;y++)
    {
        for (size_t x = 0; x < 9; x++)
        {
            if (matrix[y][x] == '.')
            {
                fprintf(fPointer,"0");

            }
            else
            {
                fprintf(fPointer,"%i",matrix[y][x]);
            }       
            if ((x+1)%3 == 0)
            {
                fprintf(fPointer," ");
            }
        }
        fprintf(fPointer,"\n");
        if ((y+1)%3 == 0)
        {
            fprintf(fPointer,"\n");
        }
    

    }

    fclose(fPointer);
}

    
 void affichage (int matrice[9][9])
{
    puts("------------------");
    for (int i=0; i<9; i++)
    {
        for (int j=0; j<9; j++)
        {
            printf( ((j+1)%3) ? "%d " : "%d|", matrice[i][j]);
        }
        putchar('\n');
        if (!((i+1)%3))
            puts("------------------");
    }
    puts("\n");
}



