/*
Name: Jatin Gupta
zID / email: z5240221@ad.unsw.edu.au
Date last modified: 27/06/2019
Name of course and session: COMP9024 19T2
Task: puzzle client
Link to spec: https://webcms3.cse.unsw.edu.au/COMP9024/19T2/resources/27266 
*/

#include "boardADT.h"

int main(void) {
	
	Board start_board = create_board();
	Board goal_board = create_board();
	
	if(!check_boards_validity(start_board, goal_board)) {
		fprintf(stderr, "Invalid board");
		return EXIT_FAILURE;
	}
	
	printf("start:");
	print_board(start_board);
	
	printf("\ngoal:");
	print_board(goal_board);
	
	if(solvable(start_board, goal_board)) {
		printf("\nsolvable\n");
	} else {
		printf("\nunsolvable\n");
	}
	
	return EXIT_SUCCESS;
}
