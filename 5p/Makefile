main: tp5.o main.o
	gcc tp5.o main.o -o main -Wall -ansi

main.o: main.c
	gcc -c main.c -o main.o

tp5.o: tp5.c
	gcc -c tp5.c -o tp5.o

clean: 
	rm -f *.o
	rm -f main
