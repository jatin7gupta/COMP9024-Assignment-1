#include<stdio.h>
#include<stdlib.h>
#include<math.h>


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
	
	int start_board[4];
	int goal_board[4];
	
	int length_start_board = input(start_board);
	int length_goal_board = input(goal_board);

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
	return EXIT_SUCCESS;
}
