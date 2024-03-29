git push -u origin masterCC=gcc
CFLAGS=-Wall -Werror -g

scanner : main.o Scan.o Page.o
	gcc -g -o scanner main.o Scan.o Page.o

main.o : main.c Scan.h Page.h
Scan.o : Scan.c Scan.h Page.h
Page.o : Page.c Page.h

clean:
	rm -f scanner *.o
