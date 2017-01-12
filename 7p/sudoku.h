#ifndef __SUDOKU__
#define __SUDOKU__

typedef int Board[9][9];

void initialize_empty_board();
void print_board(Board grid);
int get_cell(int, int, int*, int*);
void play(Board grid);

#endif
