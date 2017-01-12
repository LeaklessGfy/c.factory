#include <stdio.h>
#include <MLV/MLV_all.h>

#include "sudoku.h"
#include "ui.h"

void initialize_empty_board()
{
    UI_init_window();
}

void print_board(Board grid)
{
    UI_print_sudoku(grid);
    MLV_actualise_window();
    play(grid);
}

int get_cell(int x, int y, int *board_x, int *board_y)
{
    x = (x - CELL_WIDTH) / CELL_WIDTH;
    y = (y - CELL_HEIGHT) / CELL_HEIGHT;

    if (x > 3 && x < 7)
        x = x - 1;
    else if (x > 6)
        x = x - 2;
    
    if (y > 3 && y < 7)
        y = y - 1;
    else if (y > 6)
        y = y - 2;

    printf("x = %d\n", x);
    printf("y = %d\n", y);

    *board_x = x;
    *board_y = y;
    
    return 1;
}

void play(Board grid)
{
    int run, mouse_x, mouse_y, bx, by;
    
    mouse_x = mouse_y = run = 1;
    
    while (run)
    {
        MLV_wait_mouse(&mouse_x, &mouse_y);
        get_cell(mouse_x, mouse_y, &bx, &by);
        
        UI_print_selection();
        MLV_actualise_window();
    }
}
