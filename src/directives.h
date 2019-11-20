#ifndef _DIRECTIVES_H_
#define _DIRECTIVES_H_

extern FILE *out;

struct define {
	char *key;
	char *value;
	unsigned int keyLength;
	unsigned int valueLength;
	struct define *next;
};
typedef struct define Define;

/**
 * Includes a file's contents (#include)
 * @param [in] The path of the file to include
 */
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

/**
 * Initializes the Define struct (a linked list)
 * @param [out] Pointer to a Define struct
 */
void define_init(Define *d) {
	d->key = malloc(10);
	d->value = malloc(10);
	d->keyLength = 10;
	d->valueLength = 10;
	d->next = NULL;
}

/**
 * Call at the end to any memory used in parsing for #define
 * @param [in] Pointer to a Define struct
 * @remarks Call only once, on the "head" (first in the list)
 */
void define_free(Define *d) {
	free(d->key);
	free(d->value);
	if (d->next != NULL) define_free(d->next);
}

#endif
