#include<stdio.h>
#include<stdlib.h>

void print_array(int *array, int length) {
	for (int j =0; j < length; j++) {
		printf("%d    ,", *array);
		array++;
	}
}

int main(void) {
	int array[4];
	int c = EOF;
	int length_initial_board = 0;
	
	
	while(c != '\n' && (c = getchar()) != '\n' && c!=EOF) {
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
		              array[length_initial_board++] = sum;
		              break;
		    case 'b': array[length_initial_board++] = -1;
		    case ' ':
		    case '\t':
		    case '\n':
		              break;
		    default:  fprintf(stderr, "Invalid character %c\n", c);
        }
	}
	
	print_array(array, length_initial_board);
	return EXIT_SUCCESS;
}
