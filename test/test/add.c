#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

void main(void) {
	
	char str[] = "Happy new year!!";
	char substr[256];
	char *ptr;

	printf("Input sub string to find in String \"%s\"....", str);
	printf("\nInput string...");
	scanf("%s", substr);

	ptr = strstr(str, substr);

	printf("ptr...%x", ptr);
	printf("str...%x", str);

	if (ptr)
		printf("\nString position: %d\n", ptr-str);
	else
		printf("\nCannot find sub string...\n");
	
	printf("From...%s\n", ptr);

	getch();
}