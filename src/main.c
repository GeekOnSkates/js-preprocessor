#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "directives.h"
#include "misc.h"

FILE *out = NULL;

Define head = { 0 };

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
		perror("Error opening file");
		return 0;
	}
	out = fopen(argv[1], "w");
	if (out == NULL) {
		perror("Error opening file");
		return 0;
	}
	define_init(&head);
	char *data = malloc(120);
	char c = 0; int i = 0; int max = 120;
	char includeFound = 0, inQuotes = 0, quoteEscaped = 0;
	while(c != EOF) {
		c = fgetc(in);
		if (inQuotes) {
			if (c != EOF) fputc(c, out);
			quoteEscaped = c == '\\' && (inQuotes == '\'' || inQuotes == '"');
			if (c == !quoteEscaped) inQuotes = 0;
			continue;
		}
		if (c == '#') {
			char first[11];
			fgets(first, 10, in);
			if (strcmp(first, "include \"") == 0) {
				i = 0;
				includeFound = 1;
				continue;
			}
			else {
				fputc('#', out);
				fputs(first, out);
			}
		}
		if (includeFound) {
			if (c == '\"') {
				include(data);
				memset(data, 0, sizeof(data));
				includeFound = 0;
				inQuotes = 0;
				i = 0;
				continue;
			}
			if (c != EOF) data[i] = c;
			i++;
			if (i == max) {
				data = realloc(data, max + 20);
				max += 20;
			}
			continue;
		}
		if (c != EOF && c != '#') fputc(c, out);
		if (c == '\'' || c == '"') inQuotes = c;
	}
	define_free(&head);
	free(data);
	fclose(in);
	fclose(out);
}
