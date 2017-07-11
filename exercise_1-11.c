// Exercise 1-11.
// How would you test the word count program? What kinds of input are most
// likely to uncover bugs if there are any?

#include <stdio.h>
#include <stdlib.h>

#define IN  1 /* inside  a word */
#define OUT 0 /* outside a word */

/* count lines, words, and characters in input */
int count_words()
{
	int state = OUT;
	int c, nl, nw, nc;
	nl = nw = nc = 0;

	while ((c = getchar()) != EOF) {
		++nc;
		if (c == '\n')
			++nl;
		if (c == ' ' || c == '\n' || c == '\t')
			state = OUT;
		else if (state == OUT) {
			state = IN;
			++nw;
		}
	}
	printf("%d %d %d\n", nl, nw, nc);
}

int check_count_words(const char *string, int nl, int nw, int nc)
{
}

int main()
{
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
