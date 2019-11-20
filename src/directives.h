#ifndef _DIRECTIVES_H_
#define _DIRECTIVES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern FILE *out;
extern FILE *in;
extern char inQuotes;
extern char quoteEscaped;

struct define {
	char *key;
	char *value;
	unsigned int keyLength;
	unsigned int valueLength;
	struct define *next;
};
typedef struct define Define;

/**
 * Checks if a character is the start of a #directive,
 * processes it if it is, prints it to the file if not
 * @param [in] The last character read from the input file
 * @returns 1 if it was a #directive, 0 (false) otherwise
 */
char isDirective(char c);

/**
 * Includes a file's contents (#include)
 * @param [in] The path of the file to include
 */
void include(char *path);

/**
 * Initializes the Define struct (a linked list)
 * @param [out] Pointer to a Define struct
 */
void define_init(Define *d);

/**
 * Call at the end to any memory used in parsing for #define
 * @param [in] Pointer to a Define struct
 * @remarks Call only once, on the "head" (first in the list)
 */
void define_free(Define *d);

#endif
