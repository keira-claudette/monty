#include "monte.h"
/**
 * readlines - reads the lines from a file and stores them in an array
 * @filepointer: pointer to the file to be read
 * Return: pointer to the array of strings
 */

char **readlines(FILE *filepointer)
{
	char *line;
	size_t bufsize = 0;
	char **lines = NULL;
	int i = 0;

	if (!filepointer)
	{
		perror("Error: Can't open file <file>");
		exit(EXIT_FAILURE);
	}
/* read the lines from opcode file into an array of lines */
	while (getline(&line, bufsize, filepointer) != -1)
	{
		lines[i] = line;
		i++;
	}

	return (lines);
}
