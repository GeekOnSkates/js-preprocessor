#ifndef _DIRECTIVES_H_
#define _DIRECTIVES_H_

extern FILE *out;

/**
 * Includes a file's contents (#include)
 * @param[in] The path of the file to include
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

#endif
