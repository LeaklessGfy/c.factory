#include <stdio.h>

#include "sudoku.h"
#include "in_out.h"

int main(int argc, char* argv[]){
  Board B;
  fread_board(argv[1], B);
  initialize_empty_board();
  print_board(B);

  return 0;
}
