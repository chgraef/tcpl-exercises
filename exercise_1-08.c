// Exercise 1-8.
// Write a program to count blanks, tabs, and newlines.

#include <assert.h>
#include <stdio.h>

int main()
{
	// read this source file and count blanks, tabs and newlines
	FILE *file = fopen(__FILE__, "r");
	int c;
	int blanks = 0, tabs = 0, newlines = 0;
	while ((c = fgetc(file)) != EOF)
	{
		blanks += (c == ' ');
		tabs += (c == '\t');
		newlines += (c == '\n');
	}
	fclose(file);

	printf(	"blanks: %d\n"
		"tabs: %d\n"
		"newlines: %d\n",
		blanks, tabs, newlines);

	// The following asserts are just for checking the correctness of this program
	// and need to be adjusted if this file is changed.
	assert(blanks   == 95);
	assert(tabs     == 27);
	assert(newlines == 31);
}
