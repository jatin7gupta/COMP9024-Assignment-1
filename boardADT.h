/*
Name: Jatin Gupta
zID / email: z5240221@ad.unsw.edu.au
Date last modified: 27/06/2019
Name of course and session: COMP9024 19T2
Task: Header file for puzzle.c and boardADT.c
Link to spec: https://webcms3.cse.unsw.edu.au/COMP9024/19T2/resources/27266 
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct board *Board;

Board create_board();

int check_boards_validity(Board, Board);

int solvable(Board, Board);

void print_board(Board);
