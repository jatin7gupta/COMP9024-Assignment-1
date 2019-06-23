#include<stdio.h>
#include<stdlib.h>

  

void print_board(int *array, int length) {
	for (int j = 0; j < length; j++) {
		if (*(array + j) == -1) {
			printf(" %c", 'b');
		} else {
		    printf(" %d", *(array + j));
		}
	}
}


int input(int *board) {
	
	int c = EOF;
	int board_length = 0;
	
	
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
		              *(board + board_length++) = sum;
		              break;
		    case 'b': *(board + board_length++) = -1;
		    case ' ':
		    case '\t':
		    case '\n':
		              break;
		    default:  fprintf(stderr, "Invalid character %c\n", c);
		    		  return -1; //error
        }
	}
	return board_length;
}

int search(int *board, int length) {
//TODO
	int return_value = 0;
	return return_value;
}


int check_board_validity(int *board, int length) {
	int result = search(board,length);
	//TODO
	return result;
}

int main(void) {
	
	
	int start_board[4];
	int length_start_board = input(start_board);
	
	int start_board_validity = check_board_validity(start_board, length_start_board);
	printf("state %d", start_board_validity);
	/*
	int goal_board[4];
	int length_goal_board = input(goal_board);
	
	if (length_start_board < 0 || length_goal_board < 0) {
		return EXIT_FAILURE;
	}
	
	int goal_board_validity = check_board_validity(goal_board, length_goal_board);
	
	
	printf("\ngoal:");
	print_board(goal_board, length_goal_board);
	*/
	printf("\nstart:");
	print_board(start_board, length_start_board);
	
	return EXIT_SUCCESS;
}