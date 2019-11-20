#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "directives.h"
#include "misc.h"

FILE *out = NULL;

int main(int argc, const char **argv) {
	if (argc != 3
	|| strcmp(argv[1], "-h") == 0
	|| strcmp(argv[1], "--help") == 0
	|| strcmp(argv[1], "/h") == 0
	|| strcmp(argv[1], "?") == 0) {
		instructions();
		return 0;
	}
	FILE *in = NULL;
	in = fopen(argv[2], "r");
	if (in == NULL) {
		perror("Error opening file:");
		return 0;
	}
	out = fopen(argv[1], "w");
	if (out == NULL) {
		perror("Error opening file:");
		return 0;
	}
	char *data = malloc(120);
	char c = 0; int i = 0; int max = 120;
	char includeFound = 0;
	while(c != EOF) {
		if (i == 0) {
			char first[11];
			fgets(first, 11, in);
			if (strcmp(first, "#include \"") == 0)
				includeFound = 1;
		}
		c = fgetc(in);
		if (includeFound) {
			
			if (c == '\"') {
				include(data);
				memset(data, 0, sizeof(data));
				includeFound = 0;
				i = 0;
			}
			else {
				data[i] = c;
			}
			i++;
			if (i == max - 1) {
				data = realloc(data, max + 20);
				max += 20;
			}
			continue;
		}
		i++;
		if (c != EOF) fputc(c, out);
	}
	free(data);
	fclose(in);
	fclose(out);
}
