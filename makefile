main: main.c
	gcc -Wall -g -o main *.c -Wno-unused-result

clean: 
	rm -f main