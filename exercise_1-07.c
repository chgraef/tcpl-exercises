// Exercise 1-7.
// Write a program to print the value of EOF.

#include <assert.h>
#include <stdio.h>

int main()
{
	assert(EOF == -1);
	printf("The value of EOF is %d\n", EOF);
}
