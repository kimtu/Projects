#include <stdio.h>
#include <io.h>
#include <stdlib.h>
#include <conio.h>

#include "textview.h"

void main(int argc, char * argv[]) {
	if (argc==2) {
		text_view(argv[1]);
	} else {
		printf("사용방법: textview 파일경로\n");
	}

}

void text_view(char *filename){
	
	FILE *fp;
	long size;
	char *buffer;
	char *current_position;
	char c;
	int line_number = 1;

	fp = fopen(filename, "rb");
	if (fp==NULL) {
		printf("debug_msg: file pointer is NULL...");
		exit(-1);
	}

	size = get_file_size(fp);

	printf("debug_msg: file size is ...%d\n", size);

	buffer = (char *)malloc(size+1);
	
	fread(buffer, 1, size, fp); // total number of bytes is size + 1
	buffer[size] = EOF;

	current_position = buffer;

	current_position = display_page(&line_number, current_position);

	do {
		//printf("Enter - next page / Space - next row / ESC - terminate\r");
		c = getch();
		printf("\r");

		switch(c) {
			case ENTER:
				/* print next page */
				current_position = display_page(&line_number, current_position);
				break;
			case SPACE:
				current_position = display_row(&line_number, current_position);
				break;
			case ESC:
				/* terminate */
				return;
			default:
				break;
		}

	}while(*current_position!=EOF);



}

long get_file_size(FILE *fp) {
	long size;
	size = filelength(fileno(fp));

	return size;
}

char* display_page(int *line_number, char *current_position) {

	int count = 0;
	while(count<ROW && *current_position!=EOF) {
		current_position = display_row(line_number, current_position);
		count++;
	}

	return current_position;
}

char* display_row(int *line_number,  char *current_position) {
	if (*current_position==EOF) {
		return current_position;
	}

	printf("%5d ", *line_number);
	(*line_number)++; 
	while(*current_position!='\n' && *current_position!=EOF) {
		putchar(*current_position);
		current_position++;
	}

	if (*current_position=='\n') {
		putchar(*current_position);
		current_position++;
	}

	return current_position;
}