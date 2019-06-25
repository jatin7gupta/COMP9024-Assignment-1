#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct board *Board;

Board create_board();

int check_boards_validity(Board, Board);

int solvable(Board, Board);

void print_board(Board);
