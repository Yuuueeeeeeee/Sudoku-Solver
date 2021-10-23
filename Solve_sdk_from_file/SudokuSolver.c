
#include <stdio.h>
#include <stdlib.h>

int already_in_line(int grid[9][9], int ligne,int val) 
{
    for (int x = 0; x <= 8; x++)
        if (grid[ligne][x] == val)
            return 0;
    return 1;
}

int already_in_column (int grid[9][9],int colonne,int val)
{
    for (int x = 0; x <= 8; x++)
        if (grid[x][colonne] == val)
            return 0;
    return 1;
}

int already_in_square (int grid[9][9], int ligne,int colonne, int val)
{
    int initLigne = ligne - ligne % 3;
    int initColonne = colonne - colonne % 3;
   
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + initLigne][j + initColonne] == val)
                return 0;
 
    return 1;

}



int canWePut(int grid[9][9], int ligne,int colonne, int val)
{
     return (already_in_square(grid,ligne,colonne,val) && already_in_column(grid,colonne,val) && already_in_line(grid,ligne,val));
}


int solve_rec(int grid[9][9], int ligne, int colonne)
{
     // Cas ou on arrive a la fin du sudoku
     // On stop la reccusion
    if (colonne == 9 && ligne == 8 )
        return 1;
 
    //Si la colonne passe a 9 alors on change de ligne
    if (colonne >= 9)
    {       
        colonne = 0;
        ligne += 1;
    }
   
    // On regarde si la colonne contient une valeur differente de 0, si oui on applique la recursion
    if (grid[ligne][colonne] != 0)
        return solve_rec(grid,ligne,colonne + 1);

    for (int currentNumber = 1; currentNumber < 10; currentNumber++)
    {
        //On regarde ici si c'est possible d'inserer le nombre courant vu que la case ici est vide
        if (canWePut(grid,ligne,colonne,currentNumber))
        {
            //Cas ou on considere possible, on attribue a la case grid[ligne][colonne] le nombre courant
            grid[ligne][colonne] = currentNumber;
           
            //On check si ce que l'on a mis dans la case est correct a la prochaine reccursion
            if (solve_rec(grid,ligne,colonne + 1))
                return 1;
        }
       
        // On ne passe pas le test de canWePut, de ce fait on repars du chiffre et on reset le chiffre dans la case
        grid[ligne][colonne] = 0;
    }

    //Impossible de resoudre le sudoku
    return 0;
}

