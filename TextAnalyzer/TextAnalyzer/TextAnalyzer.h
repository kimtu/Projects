#define TAB 9
#define SPACE 32

#define TRUE 1
#define FALSE 0

#define NUMBER_OF_ALPHABET 26

void analyzer_text(char *filename);

void display_character_count(FILE *fp);
int is_tab(char c);
int is_space(char c);

void display_word_count(FILE *fp);

void display_alphabet_count(FILE *fp);