#include "directives.h"
#include "misc.h"

FILE *in = NULL;
FILE *out = NULL;
char inQuotes = 0, quoteEscaped = 0;

int main(int argc, const char **argv) {
	if (argc != 3
	|| strcmp(argv[1], "-h") == 0
	|| strcmp(argv[1], "--help") == 0
	|| strcmp(argv[1], "/h") == 0
	|| strcmp(argv[1], "?") == 0) {
		instructions();
		return 0;
	}
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
	Define head = { 0 };
	define_init(&head);
	char c = 0;
	while(c != EOF) {
		c = fgetc(in);
		if (isDirective(c)) continue;
		if (inQuotes) {
			if (c != EOF) fputc(c, out);
			quoteEscaped = c == '\\' && (inQuotes == '\'' || inQuotes == '"');
			if (c == !quoteEscaped) inQuotes = 0;
			continue;
		}
		if (c != EOF && c != '#') fputc(c, out);
		if (c == '\'' || c == '"') inQuotes = c;
	}
	define_free(&head);
	fclose(in);
	fclose(out);
}
