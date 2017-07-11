// Exercise 1-2.
// Experiment to find out what happens when prints's argument string contains
// \c, where c is some character not listed above.

#include <stdio.h>

int main()
{
	printf("a: '\a'\n"); // alert (bell)
	printf("b: '\b'\n"); // backspace
	printf("c: '\c'\n"); // warning: unknown escape sequence
	printf("d: '\d'\n"); // warning: unknown escape sequence
	printf("e: '\e'\n");
	printf("f: '\f'\n"); // formfeed
	printf("g: '\g'\n"); // warning: unknown escape sequence
	printf("h: '\h'\n"); // warning: unknown escape sequence
	printf("i: '\i'\n"); // warning: unknown escape sequence
	printf("j: '\j'\n"); // warning: unknown escape sequence
	printf("k: '\k'\n"); // warning: unknown escape sequence
	printf("l: '\l'\n"); // warning: unknown escape sequence
	printf("m: '\m'\n"); // warning: unknown escape sequence
	printf("n: '\n'\n"); // newline
	printf("o: '\o'\n"); // warning: unknown escape sequence
	printf("p: '\p'\n"); // warning: unknown escape sequence
	printf("q: '\q'\n"); // warning: unknown escape sequence
	printf("r: '\r'\n"); // carriage return
	printf("s: '\s'\n"); // warning: unknown escape sequence
	printf("t: '\t'\n"); // horizontal tab
	//printf("u: '\u'\n"); // error: \u used with no following hex digits
	printf("v: '\v'\n"); // vertical tab
	printf("w: '\w'\n"); // warning: unknown escape sequence
	//printf("x: '\x'\n"); // error: \x used with no following hex digits
	printf("y: '\y'\n"); // warning: unknown escape sequence
	printf("z: '\z'\n"); // warning: unknown escape sequence
}
