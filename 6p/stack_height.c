#include <stdio.h>
#include <stdlib.h>

/* Display indentation following the depth of recursion */
void make_space(int n){
  int i;

  for (i=0 ; i<n ; i++)
    printf("  ");
}

/* Recursive function displaying the height of the execution stack */
int stack_adr(int n, int* height, int* start_adr){
  int p=n;

  if (n >= 0){
    make_space(n);
    printf("Recursive climbing call : %d\n", p);
    make_space(n);
    printf("Adr pointer : %p and Adr local variable : %p\n", height, &p);
    make_space(n);
    printf("Stack jump : %ld\n", height-&p);
    make_space(n);
    printf("Stack total height : %ld\n\n", start_adr-&p);

    stack_adr(n-1, &p, start_adr);

    make_space(n);
    printf("Recursive descending call : %d\n", p);
    make_space(n);
    printf("Stack total height : %ld\n\n", start_adr-&p);
  }
  else{
    printf("LAST RECURSION\n\n");
  }
  return p;
}

void dirty_calc(void) {
    int i;
    double x, y, *o;
    
    x = 10000000000000000000.5;
    y = 10000000000000000000.5;
    
    for (i = 1; i < 9999999; i++)
    {
        o = malloc(sizeof(double) * i);
        *o = x + y * x + y;
    }
}

int main(int argc, char* argv[]){
  int i;

  if (argc != 2){
    fprintf(stderr, "Nope, I need one positive integer in argument to work properly.\n");
  }
    
    /*dirty_calc();*/

  stack_adr(atoi(argv[1]), &i, &i);

  return 0;
}
