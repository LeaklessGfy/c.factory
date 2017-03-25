#include <stdio.h>
#include <stdlib.h>
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

int get_cell_ui(int x, int y, int *board_x, int *board_y)
{
    x = (x - CELL_WIDTH) / CELL_WIDTH;
    y = (y - CELL_HEIGHT) / CELL_HEIGHT;

    printf("ui x = %d\n", x);
    printf("ui y = %d\n", y);

    *board_x = x;
    *board_y = y;
    
    return 1;
}

void get_cell(int x, int y, int *cell_x, int *cell_y)
{
    if (x > 3 && x < 7)
        x = x - 1;
    else if (x > 6)
        x = x - 2;
    
    if (y > 3 && y < 7)
        y = y - 1;
    else if (y > 6)
        y = y - 2;
    
    printf("cell x = %d\n", x);
    printf("cell y = %d\n", y);
    
    *cell_x = x;
    *cell_y = y;
}

int is_valid_cell(int x, int y)
{
    int valid[] = {0,1,2,4,5,6,8,9,10};
    int i, vx, vy;
    
    vy = vx = 0;
    
    if (x < 0 || x > 10)
        return 0;
    
    if (y < 0 || y > 10)
        return 0;
    
    for (i = 0; i < 9; i++)
    {
        if (x == valid[i])
            vx = 1;
        if (y == valid[i])
            vy = 1;
    }
    
    if (vx != 1 || vy != 1)
        return 0;
    
    return 1;
}

int is_valid_selection(int x, int y)
{
    if (x < 17 || x > 21)
        return 0;
    
    if (y < 0 || y > 4)
        return 0;
    
    return 1;
}

int is_define_cell(Board grid, int x, int y)
{
    int cy, cx;
    
    get_cell(x, y, &cx, &cy);
    if (grid[cx][cy] != 0)
        return 1;
    
    return 0;
}

char* get_selection_value(int x, int y)
{
    return "1";
}

void display_selection(Board grid, int x, int y)
{
    UI_print_sudoku(grid);
    UI_highlightcell(
        (CELL_WIDTH * x) + CELL_WIDTH, 
        (CELL_HEIGHT * y) + CELL_HEIGHT, 
        MLV_COLOR_INDIAN_RED
    );
}

void wait_for_cell(Board grid, int *x, int *y)
{
    int mouse_x, mouse_y;
    
    MLV_wait_mouse(&mouse_x, &mouse_y);
    get_cell_ui(mouse_x, mouse_y, x, y);

    if (!is_valid_cell(*x, *y) || is_define_cell(grid, *y, *x))
        wait_for_cell(grid, x, y);
    
    UI_print_selection();
    display_selection(grid, *x, *y);
    MLV_actualise_window();
}

void wait_for_selection(Board grid, int *x, int *y)
{
    int mouse_x, mouse_y;
    
    MLV_wait_mouse(&mouse_x, &mouse_y);
    get_cell_ui(mouse_x, mouse_y, x, y);
    
    if (!is_valid_selection(*x, *y))
    {
        if (!is_valid_cell(*x, *y) || is_define_cell(grid, *x, *y))
            wait_for_selection(grid, x, y);
    }
}

void play(Board grid)
{
    int run, mouse_x, mouse_y;
    int bx, by, bx2, by2, cx, cy;
    char *val;
    
    mouse_x = mouse_y = run = 1;
    
    while (run)
    {
        /* GET CELL */
        wait_for_cell(grid, &bx, &by);
        
        /* GET SELECTION */
        MLV_wait_mouse(&mouse_x, &mouse_y);
        get_cell_ui(mouse_x, mouse_y, &bx2, &by2);
        
        if (!is_valid_selection(bx2, by2))
        {
            if (!is_valid_cell(bx2, by2) || is_define_cell(grid, bx2, by2))
            {
                UI_print_sudoku(grid);
                MLV_actualise_window();
                continue;
            }
            
            display_selection(grid, bx, by);
            continue;
        }
        
        val = get_selection_value(bx2, by2);
        UI_drawcell(
            (CELL_WIDTH * bx) + CELL_WIDTH, 
            (CELL_HEIGHT * by) + CELL_HEIGHT, 
            val
        );
        
        get_cell(bx, by, &cy, &cx);
        grid[cx][cy] = atoi(val);
        MLV_actualise_window();
    }
}
