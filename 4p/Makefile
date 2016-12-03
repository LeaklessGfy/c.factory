main: stack.o main.o
	gcc stack.o main.o -o main -Wall -ansi
    
stack.o: stack.c
	gcc -c stack.c -o stack.o

main.o: main.c
	gcc -c main.c -o main.o

clean: 
	rm -f *.o
	rm -f main
    