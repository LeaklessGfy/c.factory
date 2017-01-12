#include <MLV/MLV_all.h>
#include <stdlib.h>

#include "ui.h"
#include "sudoku.h"

void UI_init_window(void)
{
    MLV_create_window("MAIN", "test", 1200, 800);
}

void UI_print_sudoku(Board grid)
{
    int i, j, x, y, check_y, check_x;
    char val[2];
    char empty[3] = "  ";
    
    check_x = check_y = 0;
    x = CELL_WIDTH;
    y = CELL_HEIGHT;
    
    for (i = 0; i < 9; i++)
    {   
        for (j = 0; j < 9; j++)
        {   
            if (grid[i][j] != 0)
                sprintf(val, "%d", grid[i][j]);
            else
                strcpy(val, empty);
                
            MLV_draw_adapted_text_box(
                x, 
                y, 
                val, 
                20, 
                MLV_COLOR_SNOW,
                MLV_COLOR_SNOW,
                MLV_COLOR_BLACK, 
                MLV_TEXT_CENTER
            );

            check_y++;
            x = x + CELL_WIDTH;
        
            if (check_y == 3)
            {
                x = x + CELL_WIDTH;
                check_y = 0;
            }
        }
        
        check_x++;
        y = y + CELL_HEIGHT;   
        
        if (check_x == 3)
        {
            y = y + CELL_HEIGHT;
            check_x = 0;
        }
        
        x = CELL_WIDTH;
        check_y = 0;
    }
}

void UI_print_selection(void)
{
    int i, j, x, y, num;
    char val[3];
    
    num = 1;
    x = 850;
    y = CELL_HEIGHT;
    
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            x = x + CELL_WIDTH;
            sprintf(val, "%d", num);
            
            MLV_draw_adapted_text_box(
                x, 
                y, 
                val, 
                20, 
                MLV_COLOR_INDIAN_RED, 
                MLV_COLOR_SNOW, 
                MLV_COLOR_BLACK, 
                MLV_TEXT_CENTER
            );
            
            num++;
        }
        
        x = 850;
        y = y + CELL_HEIGHT;
    }
    
}
