#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct board *Board;
struct board {
	int *board;
	int size;
};

void print_board(Board input_board) {
	for (int j = 0; j < input_board->size; j++) {
		if (*(input_board->board + j) == -1) {
			printf(" %c", 'b');
		} else {
		    printf(" %d", *(input_board->board + j));
		}
	}
}


Board input(Board input_board) {
	
	int *board = input_board->board;
	board = malloc(sizeof(int));
	if(board == NULL) {
		fprintf(stderr, "malloc() failed\n");
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
		              *(board + input_board->size++) = sum;
		              board = realloc(board, (input_board->size + 1) * sizeof(int));
		              if (board == NULL) {
		                  fprintf(stderr, "realloc() failed\n");
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


int check_perfect_square(int length) {
	float float_val = sqrt(length);
	int int_val = float_val;
	return float_val == int_val;
}


int check_board_validity(int *board, int length) {
	int result = 0;
	if (check_perfect_square(length)) {
		result = search(board, length);
	}
	return result;
}

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


int main(void) {
	Board start_board;
	//Board goal_board;
	
	start_board = malloc(sizeof(struct board));
	//goal_board = malloc(sizeof(struct board));
	
	//start_board.board = malloc(sizeof(int));
	//goal_board.board = malloc(sizeof(int));
	
	/*
	if(start_board->board == NULL || goal_board->board == NULL) {
		fprintf(stderr, "Run out of memory\n");
        return EXIT_FAILURE;
	}
	*/
	start_board = input(start_board);
	check_board_validity();
	
	/*
	goal_board = input(goal_board);
	int length_start_board = start_board->size;
	int length_goal_board = goal_board->size;
	printf("%p\t%d", start_board->board,length_start_board);
	printf("%p\t%d", goal_board->board, length_goal_board);

	
	int start_board_validity = check_board_validity(start_board, length_start_board);
	int goal_board_validity = check_board_validity(goal_board, length_goal_board);
		
	if (length_start_board < 0 || length_goal_board < 0) {
		return EXIT_FAILURE;
	}
	
	if ( !(length_start_board == length_goal_board) || !(start_board_validity && goal_board_validity)) {
		fprintf(stderr, "Invalid board");
		return EXIT_FAILURE;
	} 
	int start_parity = calculate_disorder(start_board, length_start_board);
	int goal_parity =  calculate_disorder(goal_board, length_goal_board);
	
	
	printf("start:");
	print_board(start_board, length_start_board);
	printf("\ngoal:");
	print_board(goal_board, length_goal_board);
	
	if ((start_parity % 2 == 0 && goal_parity % 2 == 0) || (start_parity % 2 == 1 && goal_parity % 2 == 1)) {
		printf("\nsolvable\n");
	} else {
		printf("\nunsolvable\n");
	}
	*/
	print_board(start_board);
	return EXIT_SUCCESS;
}
