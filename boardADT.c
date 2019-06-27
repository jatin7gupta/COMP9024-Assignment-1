/*
Name: Jatin Gupta
zID / email: z5240221@ad.unsw.edu.au
Date last modified: 27/06/2019
Name of course and session: COMP9024 19T2
Task: ADT for puzzle.c
Link to spec: https://webcms3.cse.unsw.edu.au/COMP9024/19T2/resources/27266 
*/

#include "boardADT.h"

struct board {
	int *board;
	int size;
};


/*
Input- Board
Return Value: None
Usage: Prints the board and prints b for -1. 
*/
void print_board(Board input_board) {
	for (int j = 0; j < input_board->size; j++) {
		if (*(input_board->board + j) == -1) {
			printf(" %c", 'b');
		} else {
		    printf(" %d", *(input_board->board + j));
		}
	}
}


/*
Input- Board
Return Value: Board
Usage: Takes input and allocates new memory to each entered charater. 
*/
Board input(Board input_board) {
	
	int *board = input_board->board;
	board = malloc(sizeof(int));
	if(board == NULL) {
		fprintf(stderr, "malloc() failed\n");
		exit(1);
	}
	int c = EOF;
	input_board->size = 0;
	
	while(c != '\n' && (c = getchar()) != '\n' && c != EOF) {
		int sum;
		switch (c) {
		    case '0':
		    case '1':
		    case '2':
		    case '3':
		    case '4':
		    case '5':
		    case '6':
		    case '7':
		    case '8':
		    case '9': sum = 0;
		              while ((c >= '0') && (c <= '9')) {
	                      sum = 10 * sum + (c - '0'); 
	                      c = getchar();
		              }
		              // to check if number is not appended with anything
		              if(c == '\n' || c == ' ') {
				          *(board + input_board->size++) = sum;
				          board = realloc(board, (input_board->size + 1) * sizeof(int));
				          if (board == NULL) {
				              fprintf(stderr, "realloc() failed\n");
				              exit(1);
				          }
				      } else {
				          fprintf(stderr, "invalid use of character '%c' in the board\n", c);
				          exit(1);	
				      }
		              break;
		    case 'b': *(board + input_board->size++) = -1;
					  board = realloc(board, (input_board->size + 1) * sizeof(int));
					  if (board == NULL) {
					      fprintf(stderr, "realloc() failed\n");
					      exit(1);
					  }
					  break;
		    case ' ':
		    case '\t':
		    case '\n':
		              break;
		    default:  fprintf(stderr, "Invalid character %c\n", c);
		    		  exit(1);
        }
	}
	input_board->board = board;
	return input_board;
}

/*
int search(int *board, int length) {
	int count = 0;
	int count_blank = 0;
	for (int i = 1; i < length; i++) {
		for (int j = 0 ; j < length; j++) {
			if (i == *(board + j)) {
				count++;
				break;
			}
		}
	}

	for (int j = 0 ; j < length; j++) {
		if (-1 == *(board + j)) {
			count_blank++;
		}
	}
	return count_blank == 1 && length == (count_blank + count);
}
*/


/*
Input- Board
Return Value: 0 OR 1
0: Invalid board 
1: Valid Board
Usage: Checks if all the numbers in the board are between 1 to n-1 and has blank character. It creates a dictionary and mark the index of the dict as visited corresponding to the number which has been visited. 
*/
int search(int *board, int length) {
	int *dictionary = calloc(length, sizeof(int));
	if(dictionary == NULL) {
		fprintf(stderr, "malloc() failed\n");
		exit(1);
	}
	
	//filling dict with visited as 1 and for blank we assign it to zero position of dict
	for(int i = 0; i < length; i++) {
		if(*(board + i) != -1 && *(board + i) < length && *(dictionary + *(board + i)) != 1) {
			*(dictionary + *(board + i)) = 1;
		} else if(*(board + i) == -1 && *(dictionary) != 1) {
			*(dictionary) = 1;
		} else {
			return 0;
		}
	}
	// checking if all are one in dict
	for(int i = 0; i < length; i++) {
		if(*(dictionary + i) != 1) {
			return 0;
		}
	}
	free(dictionary);
	dictionary = NULL;
	return 1;
}


/*
Input- length of board
Return Value: 0 OR 1
0: Input is not perfect square
1: Input is perfect square
Usage: Checks if the input is perfect square and returns binary answer.
*/
int check_perfect_square(int length) {
	float float_val = sqrt(length);
	int int_val = float_val;
	return float_val == int_val;
}


/*
Input- board
Return Value: 0 OR 1
0: Valid Board
1: Invalid Board
Usage: Calls the check_perfect_square function and search function and retuns the value by search function.
*/
int check_board_validity(Board input_board) {
	int result = 0;
	if (check_perfect_square(input_board->size)) {
		result = search(input_board->board, input_board->size);
	}
	return result;
}


/*
Input- board and length of board
Return Value: value of disorder
Usage: Calculates the disorder as described in the specs and returns the integer value. For even board, calculates the placement of blank character as well.
*/
int calculate_disorder(int *board, int length) {
	int disorder = 0;
	for (int i = 0; i < length; i++) {
		for (int j = i+1 ; j < length; j++) {
			if (*(board + i) > *(board + j) && *(board + i) != -1 && *(board + j) != -1) {
				disorder++;
			}
		}
	}
	int board_order = (int)sqrt(length);
	// if the board order is even, we calculate the row number of the blank tile
	if (board_order % 2 == 0) {
		//even
		int index = 0;
		for (int i = 0; i < length; i++) {
			if (*(board + i) == -1) {
				index = i;
				break;
			}
		}
		disorder += (int)ceil((float)(index + 1)/board_order);
	} 
	return disorder;
}


/*
Input- None
Return Value: Board
Usage: Takes input by calling input function and returns board.
*/
Board create_board() {
	Board board_ADT = malloc(sizeof(struct board));
	if(board_ADT == NULL) {
		fprintf(stderr, "malloc() failed\n");
		exit(1);
	}
	board_ADT = input(board_ADT);
	return board_ADT;
}


/*
Input- 2 boards
Return Value: 0 OR 1
0: Valid Boards
1: Invalid Boards
Usage: Checks if the length of the two boards are equal and then calls the check_board_validity function and computes the validity of the 2 boards.
*/
int check_boards_validity(Board start_board, Board goal_board) {
	return (start_board->size == goal_board->size && check_board_validity(start_board) && check_board_validity(goal_board));
}


/*
Input- 2 boards
Return Value: 0 OR 1
0: Solvable
1: Unsolvable
Usage: calls the calculate_disorder functions and computes the solvibility of the 2 boards
*/
int solvable(Board start_board, Board goal_board) {
	int start_parity = calculate_disorder(start_board->board, start_board->size);
	int goal_parity =  calculate_disorder(goal_board->board, goal_board->size);
	return ((start_parity % 2 == 0 && goal_parity % 2 == 0) || (start_parity % 2 == 1 && goal_parity % 2 == 1));
}


