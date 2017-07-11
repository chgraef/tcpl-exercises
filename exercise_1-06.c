// Exercise 1-6.
// Verify that the expression getchar() != EOF is 0 or 1.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	// §6.5.9 Equality operators
	// 6) "Each of the operators yields 1 if the specified relation is true
	// and 0 if it is false." (ISO/IEC 9899:201x, N1570 6.5.9.3)
	//
	// Now we have to prove that "getchar() != EOR" yields both values.
	// We are going to fork(), then write some bytes on one side, read them
	// on the other side and finally check that we read both values for
	// "getchar() != EOF".

	int mypipe[2];

	// Create the pipe.
	if (pipe(mypipe))
	{
		fprintf(stderr, "Pipe failed.\n");
		return EXIT_FAILURE;
	}

	// write something on the child side
	pid_t pid = fork();
	if (pid == 0)
	{
		close (mypipe[0]);
		FILE *stream = fdopen(mypipe[1], "w");
		fprintf(stream, "Hello, world!");
		fclose(stream);
		return 0;
	}

	// read on the parent side
	close(mypipe[1]);
	dup2(mypipe[0], STDIN_FILENO);
	close(mypipe[1]);
	int c, seen[] = {0, 0};
	do {
		c = (getchar() != EOF);
		assert(c == 0 || c == 1);
		seen[c] = 1;
	} while (c);

	// check if both values were observed for "getchar() != EOF"
	int claim_verified = (seen[0] && seen[1]);
	assert(claim_verified);
	printf("%s", (claim_verified)? "verified" : "not verified");
	return (claim_verified)? EXIT_SUCCESS : EXIT_FAILURE;
}
