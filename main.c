#include<stdio.h>
#include<stdlib.h>

int main(void) {
	int array[5];
	int c = EOF;
	int i = 0;
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
		              array[i++] = sum;
		              break;
		    case 'b': array[i++] = -1;
		    case ' ':
		    case '\t':
		    case '\n':
		              break;
		    default:  fprintf(stderr, "Invalid character %c\n", c);
        }
	}
	for (int j =0; j < 5; j++) {
		printf("%d __", array[j]);
	}
	return EXIT_SUCCESS;
}
