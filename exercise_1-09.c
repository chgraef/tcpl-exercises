// Exercise 1-9.
// Write a program to copy its input to its output, replacing each string of
// one or more blanks by a single blank.

#include <stdio.h>

int main()
{
    int previous = getchar();
    while (previous != EOF)
    {
        int c = getchar();
        if (previous != ' ' || c != ' ')
            putchar(previous);
        previous = c;
    }
}
