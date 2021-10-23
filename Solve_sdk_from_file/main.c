# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "txt_into_matrix.h"
# include "SudokuSolver.h"


int main(int argc,char **argv)
{
    //Empty natrice
    int matrix[9][9] =
            {{0,0,0,0,0,0,0,0,0},
             {0,0,0,0,0,0,0,0,0},
             {0,0,0,0,0,0,0,0,0},
             {0,0,0,0,0,0,0,0,0},
             {0,0,0,0,0,0,0,0,0},
             {0,0,0,0,0,0,0,0,0},
             {0,0,0,0,0,0,0,0,0},
             {0,0,0,0,0,4,0,0,0},
             {0,0,0,0,0,0,0,0,0}};

    if(argc < 2 || argc > 2)
    {
        printf("Function main need 1 parameter (Path of the grid)\n");
        return 1;
    }      
   
    else
    {
        txt_into_matrix(matrix,argv[1]);
        solve_rec(matrix,0,0);
        matrix_into_txt(matrix,"grid_00.result");

        return 0;

    }

    
}


