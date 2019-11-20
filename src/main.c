#include "directives.h"
#include "misc.h"

FILE *in = NULL;
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
	read_file(in);
	define_free(&head);
	fclose(in);
	fclose(out);
}
