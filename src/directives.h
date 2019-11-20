#ifndef _DIRECTIVES_H_
#define _DIRECTIVES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern FILE *out;
extern FILE *in;

struct define {
	char *key;
	char *value;
	unsigned int keyLength;
	unsigned int valueLength;
	struct define *next;
};
typedef struct define Define;

extern Define head;

/**
 * This is the main file-reading loop
 * @param [in] Pointer to a FILE struct
 */
void read_file(FILE *file);

/**
 * Checks if a character is the start of a #directive,
 * processes it if it is, prints it to the file if not
 * @param [in] The last character read from the input file
 * @param [in] Pointer to the FILE structure we're reading
 * @returns 1 if it was a #directive, 0 (false) otherwise
 */
char is_directive(char c, FILE *file);

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
