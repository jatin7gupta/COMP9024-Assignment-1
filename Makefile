CC=dcc
CFLAGS=-O3

board: boardADT.h boardADT.c puzzle.c
	$(CC) -o puzzle boardADT.c puzzle.c
	
	

all: board

clean:
	-rm -f *.out



