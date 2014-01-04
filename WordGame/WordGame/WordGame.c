#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>


#include "WordGame.h"

void main(void) {
	play_word_game();
}

void play_word_game(void) {
	char word_list[TOTAL_COUNT][MAX_WORD] = {""};
	char read_word[MAX_WORD] = "";
	char working_word[MAX_WORD] = ""; 
	char c;
	int word_count;
	int score = 0;
	int win_score;
	int find_flag;

	srand( (unsigned int) time(NULL));
	printf("time...%d\n", (unsigned int)time(NULL));

	word_count = read_word_list("wordlist.txt", word_list);

	while(1) {
		printf("Current Score is : %d \n", score);
		printf("Figure it out!!!...\n");

		get_new_word(word_list, word_count, read_word);

		init_working_word(read_word, working_word);

		win_score = 100;

		while(1) {
			display_word(working_word);
			
			c = getch();
			if(c==ESC) {
				return;
			}
			printf("%c\n", c);

			find_flag = find_word(c, read_word, working_word);

			if (is_word_complete(read_word, working_word)) {
				display_word(working_word);
				printf("Success !!! \n\n");
				score += win_score;
				break;
			}

			if (find_flag == FALSE && win_score-5>=0) {
				win_score -=5;
			}
		}

		
	}
}

int is_word_complete(char *read_word, char *working_word) {
	if (strcmp(read_word, working_word)==0) {
		return	TRUE;
	} else {
		return FALSE;
	}
}

int find_word(char c, char *read_word, char *working_word) {
	int find_flag = FALSE;
	char *pos = read_word;
	do {

		pos = strchr(pos, c);
		if (pos) {
			working_word[pos-read_word] = c;
			find_flag = TRUE;
			pos++;
		}

	} while (pos!=NULL);

	return find_flag;
}

void display_word(char *working_word) {
	int word_length;
	int i;

	word_length = strlen(working_word);
	for(i=0; i<word_length; i++) {
		printf("%c|", working_word[i]);
	}

	printf("\n");
}

void init_working_word(char *read_word, char * working_word) {

	int word_length;
	int i;

	word_length = strlen(read_word);
	for(i=0; i<word_length; i++) {
		working_word[i] = ' ';
	}

	working_word[word_length] = 0; // null

	printf("working word length is ....%d\n", strlen(working_word));

}

void get_new_word(char word_list[][MAX_WORD], int word_count, char read_word[MAX_WORD]) {
	int index;

	index = rand()%word_count;
	printf("rand...%d\n", rand());
	strcpy(read_word, word_list[index]);

	printf("%s\n", read_word);
}

int read_word_list(char *filename, char word_list[][MAX_WORD]) {
	FILE * fp;
	int result;
	int count = 0;
	char buffer[MAX_WORD];
	int i;

	/* open file*/
	fp = fopen(filename, "rt");
	if (!fp) {
		printf("error: Cannot read the  %s file...\n", filename); 
		exit(-1);
	}

	while(1) {
		result = fscanf(fp, "%s", buffer);
		if (result == EOF)
			break;

		strcpy(word_list[count], buffer);
		
		count++;
	}

	for(i=0; i<count;i++) {
		printf("%s\n", word_list[i]);
	}

	fclose(fp);

	return count;
}