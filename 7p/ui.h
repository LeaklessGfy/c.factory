#ifndef __UI__
#define __UI__

#include "sudoku.h"
#define CELL_WIDTH 48
#define CELL_HEIGHT 55
#define CELL_CONTENT 45

void UI_init_window(void);
void UI_print_sudoku(Board);
void UI_print_selection(void);

#endif
