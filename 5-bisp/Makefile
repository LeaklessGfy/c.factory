all:
	make main
	make miroir_string
	make blasay

main: main.c
	gcc main.c -o main -Wall -ansi -lm

miroir_string: miroir_string.c
	gcc miroir_string.c -o miroir_string -Wall -ansi

blasay: blasay.c
	gcc blasay.c -o blasay -Wall -ansi

clean:
	rm -f main
	rm -f blasay
	rm -f miroir_string
