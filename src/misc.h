#ifndef _MISC_H_
#define _MISC_H_

/**
 * Shows the instructions (obviously) :)
 * @todo Include instructions on the available #directives
 * (#include, #define etc.) once they're working.
 */
void instructions() {
	printf("JAVASCRIPT PREPROCESSOR\n\n");
	printf("This program does some copy/pasting,\n");
	printf("find/replacing, and stuff like that,\n");
	printf("to a JavaScript file.  This adds new,\n");
	printf("cool features to JS without being\n");
	printf("a total rewrite of the language.\n\n");
	printf("USAGE:\n\n");
	printf("    jsp output input\n\n");
	printf("PARAMETERS:\n");
	printf("    output: name of the processed file\n");
	printf("    input: name of the file to process\n\n");
	printf("EXAMPLE:\n\n");
	printf("    jsp saveHere.js compileThis.js\n");
}

#endif
