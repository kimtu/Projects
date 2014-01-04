#define TOTAL_COUNT 1000
#define MAX_WORD 256
#define ESC 27
#define TRUE 1
#define FALSE 0

void play_word_game(void);
int read_word_list(char *filename, char word_list[][MAX_WORD]);
void get_new_word(char word_list[][MAX_WORD], int word_count, char read_word[MAX_WORD]);
void init_working_word(char *read_word, char * working_word);
void display_word(char *working_word);
int find_word(char c, char *read_word, char *working_word);
int is_word_complete(char *read_word, char *working_word);