#include <stdio.h>
#include <MLV/MLV_all.h>

#include "sudoku.h"
#include "ui.h"

void initialize_empty_board(Board grid){

}

void print_board(Board grid){
    init_window();
    
    print_sudoku(grid);
    MLV_actualise_window();
    
    play(grid);
}

int get_cell(int x, int y, int *board_x, int *board_y)
{
    x = x - 70;
    y = y - 70;
    
    if (x > 19 && x < 88 && y < 20)
        *board_x = 0;
    else if (x > 87 && x < 155)
        *board_x = 1;
    
    printf("board_x = %d\n", *board_x);
    printf("x = %d\n", x);
    printf("y = %d\n", y);
    
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
        
        print_selection();
        MLV_actualise_window();
    }
}
