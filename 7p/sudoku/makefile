CC=gcc
CFLAGS=-Wall -ansi
LDFLAGS=
OBJ=sudoku.o main.o in_out.o ui.o

sudoku: $(OBJ)
	$(CC) -o sudoku $(OBJ) $(CFLAGS) -lMLV

main.o: main.c sudoku.h in_out.h
	$(CC) -c main.c $(CFLAGS)

sudoku.o: sudoku.c sudoku.h
	$(CC) -c sudoku.c $(CFLAGS)

in_out.o: in_out.c in_out.h
	$(CC) -c in_out.c $(CFLAGS)
    
ui.o: ui.c ui.h
	$(CC) -c ui.c $(CFLAGS) -lMLV

clean: 
	rm -f *.o
	rm -f *~
	rm -f sudoku
