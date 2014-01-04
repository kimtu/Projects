#define ROW 23
#define ENTER 13
#define ESC 27
#define SPACE 32


void text_view(char *filename);
long get_file_size(FILE *fp);
char* display_page(int *line_number, char *current_position);
char* display_row(int *line_number,  char *current_position);