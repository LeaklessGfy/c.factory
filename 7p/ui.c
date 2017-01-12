#include <MLV/MLV_all.h>
#include <stdlib.h>

#include "ui.h"
#include "sudoku.h"

void init_window(void)
{
    MLV_create_window("MAIN", "test", 1200, 800);
}

void print_sudoku(Board grid)
{
    int i, j, x, y, space, check_y, check_x;
    char *val;
    
    val = (char*) malloc(sizeof(char) * 3);
    
    check_x = check_y = 0;
    space = 20;
    x = 20;
    y = space;
    
    for (i = 0; i < 9; i++)
    {   
        for (j = 0; j < 9; j++)
        {
            if (check_y != 3) {
                x = x + 70;
            }
            else {
                x = x + 100;
                check_y = 0;
            }
            
            if (grid[i][j] != 0)
            {
                sprintf(val, "%d", grid[i][j]);
            }
            else
            {
                free(val);
                val = (char*) malloc(sizeof(char) * 3);
                strcpy(val, "  ");
            }
                
            MLV_draw_adapted_text_box(
                x, 
                y, 
                val, 
                30, 
                MLV_COLOR_SNOW, 
                MLV_COLOR_SNOW, 
                MLV_COLOR_BLACK, 
                MLV_TEXT_CENTER
            );
            
            check_y++;
        }
        
        check_x++;
        
        if (check_x != 3)
        {
            y = y + 70;   
        }
        else
        {
            y = y + 100;
            check_x = 0;
        }
        
        x = 20;
        check_y = 0;
    }
    
    free(val);
}

void print_selection(void)
{
    int i, j, x, y, num;
    char val[3];
    
    num = 1;
    x = 850;
    y = 20;
    
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            x = x + 70;
            sprintf(val, "%d", num);
            
            MLV_draw_adapted_text_box(
                x, 
                y, 
                val, 
                30, 
                MLV_COLOR_INDIAN_RED, 
                MLV_COLOR_SNOW, 
                MLV_COLOR_BLACK, 
                MLV_TEXT_CENTER
            );
            
            num++;
        }
        
        x = 850;
        y = y + 70;
    }
    
}
