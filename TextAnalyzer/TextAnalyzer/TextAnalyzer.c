#include <stdio.h>
#include <conio.h>
#include "TextAnalyzer.h"

void main(int argc, char *argv[]) {
	int i;
	if(argc<2) {
		printf("Usage: TextAnalyzer full_path1, full_path2,...\n");
		return;
	}

	for (i=1; i<argc; i++) {
		analyzer_text(argv[i]);
	}	

}

void analyzer_text(char *full_path) {
	FILE *fp;

	fp = fopen(full_path, "rt");
	if (!fp) {
		printf("Cannot read the %s file...\n", full_path);
		return;
	}

	printf("------------------------------------------------------\n");
	printf("Analyzing %s file..........\n", full_path);
	printf("------------------------------------------------------\n");

	display_character_count(fp);
	printf("Press any key...\n\n");
	getch();

	display_word_count(fp);
	printf("Press any key...\n\n");
	getch();

	display_alphabet_count(fp);
	printf("Press any key...\n\n");


	
}

void display_alphabet_count(FILE *fp) {
	char c;
	char alphabet_count[NUMBER_OF_ALPHABET] = {0,};
	long character_count = 0L;
	int i;

	printf("Display counting of each alphabet character...\n");

	fseek(fp, 0L, SEEK_SET);

	while(1) {
		c = fgetc(fp);
		if (c==EOF) break;

		for (i=0; i<NUMBER_OF_ALPHABET; i++) {
			if (c=='a'+i) {
				alphabet_count[i]++;
			}
		}
	}

	for (i=0; i<NUMBER_OF_ALPHABET; i++) {
		printf("%c : %ld\n", 'a'+i, alphabet_count[i]);
	}
}

void display_word_count(FILE *fp) {
	
	char c;
	long word_count = 0L;
	fseek(fp, 0L, SEEK_SET);
	while(1) {
		c = fgetc(fp);
		if ( c==EOF ) break;

		if ( is_tab(c) || is_space(c) ) {
			word_count++;
			while( (is_tab(c) || is_space(c)) && c!=EOF ) {
				c = fgetc(fp);
			}
		}
	}

	printf("total words is ...%ld\n", word_count);
}

void display_character_count(FILE *fp) {
	char c;
	long character_count = 0L;
	fseek(fp, 0L, SEEK_SET);
	while(1) {
		c = fgetc(fp);
		if ( c==EOF ) break;

		if ( !is_tab(c) && !is_space(c) )
			character_count++;
	}
	
	printf("total count character is...%ld\n", character_count);
}

int is_tab(char c) {
	if ( c==TAB ) {
		return TRUE;
	} else {
		return FALSE;
	}
}

int is_space(char c) {
	if ( c==SPACE ) {
		return TRUE;
	} else {
		return FALSE;
	}
}