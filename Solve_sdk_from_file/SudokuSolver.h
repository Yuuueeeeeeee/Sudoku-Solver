#ifndef OCR7_SOLVER_H
#define OCR7_SOLVER_H


int already_in_column(int matrice[9][9],int x, int val);
int already_in_line(int matrice[9][9],int x, int y);
int already_in_square(int matrice[9][9],int x, int y, int val);
int canWePut(int grid[9][9], int ligne,int colonne, int val);
int solve_rec(int grid[9][9], int ligne, int colonne);

#endif //OCR7_SOLVER_H
