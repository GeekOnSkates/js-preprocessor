#include "directives.h"

void include(char *path) {
	FILE *includeThis = NULL;
	includeThis = fopen(path, "r");
	if (includeThis == NULL) {
		perror("Error opening #included file");
		return;
	}
	char c = 0;
	while (c != EOF) {
		c = fgetc(includeThis);
		if (c != EOF) fputc(c, out);
	}
	fclose(includeThis);
}

void define_init(Define *d) {
	d->key = malloc(10);
	d->value = malloc(10);
	d->keyLength = 10;
	d->valueLength = 10;
	d->next = NULL;
}

void define_free(Define *d) {
	free(d->key);
	free(d->value);
	if (d->next != NULL) define_free(d->next);
}

char isDirective(char c) {
	if (c != '#') return 0;
	char includeFound = 0; int i = 0; char first[11];
	fgets(first, 10, in);
	if (strcmp(first, "include \"") != 0) {
		fputc('#', out);
		fputs(first, out);
		return 0;
	}
	
	char *data = malloc(120); int max = 120;
	c = 0;
	while(c != '"' && c != EOF) {
		c = fgetc(in);
		if (c == '"') {
			printf("including: %s\n", data);
			include(data);
			memset(data, 0, sizeof(data));
			includeFound = 0;
			inQuotes = 0;
			i = 0;
			free(data);
			return 1;
		}
		else data[i] = c;
		i++;
		if (i == max) {
			data = realloc(data, max + 20);
			max += 20;
		}
	}
	free(data);
	return 0;
}